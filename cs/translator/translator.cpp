// convert a document tree into VM code
#include "iobuffer.h"
#include "abstract-syntax-tree.h"
#include "assembler-internal.h"
#include <string>

// to make out programs a bit neater
using namespace std ;

using namespace CS_IO_Buffers ;
using namespace Hack_Virtual_Machine ;

// grammer to be parsed:
// vm_class ::= command* eoi
// command ::= vm_operator | vm_jump | vm_func | vm_stack
// vm_operator ::= 'add' | 'and' | 'eq' | 'gt' | 'lt' | 'neg' | 'not' | 'or' | 'sub' | 'return'
// vm_jump ::= jump label
// vm_func ::= func label number
// vm_stack ::= stack segment number

// forward declare parsing functions - one per rule
static void translate_vm_class(ast root) ;
static void translate_vm_command(ast command) ;
static void translate_vm_operator(ast vm_op) ;
static void translate_vm_jump(ast jump) ;
static void translate_vm_func(ast func) ;
static void translate_vm_stack(ast stack) ;



////////////////////////////////////////////////////////////////

/************   PUT YOUR HELPER FUNCTIONS HERE   **************/
string functionName;
int ind = 0;
int inde=0;

static string nextLab(){
    ind++;
    string s = std::to_string(ind);
    string Lab = "LABEL"+s;
    return Lab;
}

static string nextRet(){
    inde++;
    string s = std::to_string(inde);
    string RetL = "RetrunLabel"+s;
    return RetL;
}

//CALL
static void function_call(string label, int number){ 
    string ReturnA = nextRet();//here we need to use a increment to make each 
    output_assembler("@"+functionName+"$"+ReturnA);   //call return to a different position
    output_assembler("D=A");
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");//push return address Label to the stack
    output_assembler("@LCL");//Push local 0 address to stack
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");
    output_assembler("@ARG"); //push argument 0 address
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");
    output_assembler("@THIS");//push this address
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");
    output_assembler("@THAT");//push that address
    output_assembler("D=M");
    output_assembler("@SP");
    output_assembler("AM=M+1");
    output_assembler("A=A-1");
    output_assembler("M=D");
    //ARG = SP-5-nArgs
    output_assembler("@SP");
    output_assembler("D=M");
    int sum = number+5;
    output_assembler("@"+std::to_string(sum));
    output_assembler("D=D-A");
    output_assembler("@ARG");
    output_assembler("M=D");
    //LCL = SP
    output_assembler("@SP");
    output_assembler("D=M");
    output_assembler("@LCL");
    output_assembler("M=D");
    //GOTO called function
    output_assembler("@"+label); 
    output_assembler("0;JMP");
    //return address label
    output_assembler("("+functionName+"$"+ReturnA+")");
}

//PUSH
static void stack_push(string segment, int number){
    if (segment == "constant")
    {
        if (number != 0)
        {
            output_assembler("@"+std::to_string(number));
            output_assembler("D=A");
            output_assembler("@SP");
            output_assembler("AM=M+1"); //SP++
            output_assembler("A=A-1");
            output_assembler("M=D");//number is in new top of stack 
        }
        else{
            output_assembler("@SP");
            output_assembler("AM=M+1"); //SP++
            output_assembler("A=A-1");
            output_assembler("M=0");//num
        }
        
    }
    else if (segment == "argument"||segment == "local"||segment == "that"||segment == "this"||segment == "temp")
    {
        if (number != 0)
        {
            if (segment == "argument")
            {
                output_assembler("@ARG");
                output_assembler("D=M");
            }
            else if (segment == "local")
            {
              output_assembler("@LCL"); 
              output_assembler("D=M");
            }
            else if (segment == "that")
            {
                output_assembler("@THAT");
                output_assembler("D=M");
            }
            else if (segment == "this")
            {
                output_assembler("@THIS");
                output_assembler("D=M");
            }
            else if (segment == "temp")
            {
                output_assembler("@R5");
                output_assembler("D=A");
            }
            output_assembler("@"+std::to_string(number));
            output_assembler("A=D+A");
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("AM=M+1");//SP++
            output_assembler("A=A-1");
            output_assembler("M=D"); 
        }
        else {
            if (segment == "argument")
            {
                output_assembler("@ARG");
                output_assembler("A=M");
            }
            else if (segment == "local")
            {
              output_assembler("@LCL"); 
              output_assembler("A=M");
            }
            else if (segment == "that")
            {
                output_assembler("@THAT");
                output_assembler("A=M");
            }
            else if (segment == "this")
            {
                output_assembler("@THIS");
                output_assembler("A=M");
            }
            else if (segment == "temp")
            {
               output_assembler("@R5");
              
            }
            
            output_assembler("D=M");
            output_assembler("@SP");
            output_assembler("AM=M+1");//SP++
            output_assembler("A=A-1");
            output_assembler("M=D"); 
        
        }
            
       
        
    }
    else if (segment == "pointer")
    {
        if (number==0)
        {
            output_assembler("@THIS");   
        }
        else if (number==1)
        {
            output_assembler("@THAT");
        }
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("AM=M+1");
        output_assembler("A=A-1");
        output_assembler("M=D");
    }
    else if (segment == "static")
    {
        //number=number+16;
        output_assembler("@"+ functionName.substr(0,functionName.find_first_of("."))+"."+ std::to_string(number)); //Classname.number
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("AM=M+1"); //SP++
        output_assembler("A=A-1"); //A back to top+1 of stack
        output_assembler("M=D");
    }
}

//POP
static void stack_pop(string segment, int number, string La){
    if (segment == "argument"||segment == "local"||segment == "that"||segment == "this")
    {
        if (segment == "argument")
        {
            output_assembler("@ARG");
        }
        else if (segment == "local")
        {
            output_assembler("@LCL");
        }
        else if (segment == "that")
        {
            output_assembler("@THAT");
        }
        else if (segment == "this")
        {
            output_assembler("@THIS");
        } 
        output_assembler("D=M");//D is the address stored in segment
        output_assembler("@"+std::to_string(number));
        output_assembler("D=D+A");//D is address stored in segment + number
        output_assembler("@R13");
        output_assembler("M=D");//RAM[R13] is the address we need
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");//D is top stack value
        output_assembler("@R13");
        output_assembler("A=M");//A is the address we want
        output_assembler("M=D");//store the top stack value in the address we want

    }
    else if (segment=="temp"||segment=="pointer")
    {

        if (segment=="temp")
        {
            output_assembler("@R5");
            output_assembler("D=A");
            output_assembler("@"+std::to_string(number));
            output_assembler("D=D+A");
        }
        else if (segment=="pointer"&&number==0)
        {
            output_assembler("@THIS");
            output_assembler("D=A");//D is the address stored in THIS
        }
        else if (segment=="pointer"&&number==1)
        {
            output_assembler("@THAT");
            output_assembler("D=A");
        }
        output_assembler("@R13");//use a location to store the address for pop
        output_assembler("M=D");
        output_assembler("@SP");
        output_assembler("AM=M-1");//sp--
        output_assembler("D=M");//D is top stack value
        output_assembler("@R13");
        output_assembler("A=M");
        output_assembler("M=D");//store top stack value in the address we want
    }
    else if (segment=="static")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");//sp--
        output_assembler("D=M");
        number=number+16;
        output_assembler("@"+std::to_string(number)); //Classname.number
        output_assembler("M=D");
    }
}


//operators
static void oper(string the_op)
{
    if (the_op=="add"||the_op=="sub"||the_op=="and"||the_op=="or")
    {
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        if (the_op=="add")
        {
            output_assembler("M=D+M");
        }
        else if (the_op=="sub")
        {
            output_assembler("M=M-D");
        }
        else if (the_op=="and")
        {
            output_assembler("M=D&M");
        }
        else if (the_op=="or")
        {
            output_assembler("M=D|M");
        }
    }
    else if (the_op=="not")
    {
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=!M");
    }
    else if (the_op=="neg")
    {
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=-M");
    }
    else if (the_op=="return")
    {
        output_assembler("@LCL"); 
        output_assembler("D=M");
        output_assembler("@5");
        output_assembler("A=D-A");
        output_assembler("D=M");
        output_assembler("@R14");
        output_assembler("M=D");//R14 stores the return address
        output_assembler("@SP");
        output_assembler("AM=M-1");//SP--
        output_assembler("D=M");
        output_assembler("@ARG");
        output_assembler("A=M");
        output_assembler("M=D");//put top stack value in address of ARG
        output_assembler("@ARG");
        output_assembler("D=M");
        output_assembler("@SP");
        output_assembler("M=D+1"); //SP stores argument 1
        output_assembler("@LCL");
        output_assembler("D=M");
        output_assembler("@1");
        output_assembler("A=D-A");
        output_assembler("D=M");
        output_assembler("@THAT");
        output_assembler("M=D");//THAT stores value in (local 0 - 1) 
        output_assembler("@LCL");
        output_assembler("D=M");
        output_assembler("@2");
        output_assembler("A=D-A");
        output_assembler("D=M");
        output_assembler("@THIS");
        output_assembler("M=D");
        output_assembler("@LCL");
        output_assembler("D=M");
        output_assembler("@3");
        output_assembler("A=D-A");
        output_assembler("D=M");
        output_assembler("@ARG");
        output_assembler("M=D");
        output_assembler("@LCL");
        output_assembler("D=M");
        output_assembler("@4");
        output_assembler("A=D-A");
        output_assembler("D=M");
        output_assembler("@LCL");
        output_assembler("M=D");
        output_assembler("@R14");//NEXT goto the return address
        output_assembler("A=M");
        output_assembler("0;JMP");

    }
    else if (the_op=="eq")
    {
        string ss = nextLab();
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("M=M-D");//M is the difference between 2nd value and top value
        output_assembler("M=!M");
        output_assembler("D=M+1");
        output_assembler("@"+functionName+"$"+ss);
        output_assembler("D;JEQ");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=0");
        output_assembler("("+functionName+"$"+ss+")");
    }
    else if (the_op=="lt")
    {
        string ss1 = nextLab();
        output_assembler("@SP");
        output_assembler("AM=M-1");//SP--
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");//D = difference
        output_assembler("M=-1");
        output_assembler("@"+functionName+"$"+ ss1);
        output_assembler("D;JLT");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=0");
        output_assembler("("+functionName+"$"+ss1+")");
    }
    else if (the_op=="gt")
    {
        string ss2 = nextLab();
        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("A=A-1");
        output_assembler("D=M-D");
        output_assembler("M=-1");
        output_assembler("@"+functionName+"$"+ss2);
        output_assembler("D;JGT");
        output_assembler("@SP");
        output_assembler("A=M-1");
        output_assembler("M=0");
        output_assembler("("+functionName+"$"+ss2+")");
    }
    else
    {
        fatal_error(0,"// bad operator - expected add,and,eq,gt,lt,not,neg,or,sub,return\n") ;
    } 

}

/************      END OF HELPER FUNCTIONS       **************/

///////////////////////////////////////////////////////////////



// the function translate_vm_class() will be called by the main program
// its is passed the abstract syntax tree constructed by the parser
// it walks the abstract syntax tree and produces the equivalent VM code as output
static void translate_vm_class(ast root)
{
    // assumes we have a "class" node containing VM command nodes
    ast_mustbe_kind(root,ast_vm_class) ;

    // tell the output system we are starting to translate VM commands for a Jack class
    start_of_vm_class() ;

    int ncommands = size_of_vm_class(root) ;

    for ( int i = 0 ; i < ncommands ; i++ )
    {
        translate_vm_command(get_vm_class(root,i)) ;
    }

    // tell the output system we have just finished translating VM commands for a Jack class
    end_of_vm_class() ;

}

// translate the current vm command - a bad node is a fatal error
static void translate_vm_command(ast command)
{
    switch(ast_node_kind(command))
    {
    case ast_vm_operator:
        translate_vm_operator(command) ;
        break ;
    case ast_vm_jump:
        translate_vm_jump(command) ;
        break ;
    case ast_vm_function:
        translate_vm_func(command) ;
        break ;
    case ast_vm_stack:
        translate_vm_stack(command) ;
        break ;
    default:
        fatal_error(0,"// bad node - expected vm_operator, vm_jump, vm_function or vm_stack\n") ;
        break ;
    }
}

// translate vm operator command into assembly language
static void translate_vm_operator(ast vm_op)
{
    // extract command specific info from the ast node passed in
    string the_op = get_vm_operator_command(vm_op) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_operator_command(the_op) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    output_assembler("// "+the_op);
    oper(the_op);
    
         

    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_jump(ast jump)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_jump_command(jump) ;
    string label = get_vm_jump_label(jump) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_jump_command(command,label) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    if (command=="goto")
    {                                //find the label address, store it in A, then @A, 0 jmp
        output_assembler("@"+functionName+"$"+label);
        output_assembler("0;JMP");
    }
    else if (command=="if-goto"){

        output_assembler("@SP");
        output_assembler("AM=M-1");
        output_assembler("D=M");
        output_assembler("@"+functionName+"$"+label);
        output_assembler("D;JNE");
    }
    else if (command=="label")
    {
        output_assembler("("+functionName+"$"+label+")");

    }
    else{
        fatal_error(0,"// bad jump - expected goto, if-goto\n") ;
    }
           
    

    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_func(ast func)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_function_command(func) ;
    string label = get_vm_function_label(func) ;
    int number = get_vm_function_number(func) ;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_func_command(command,label,number) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // 
    //output_assembler(func);
    //add helper function for each case, command only has call or fuction
    if (command == "call")
    {
        output_assembler("// call "+label+" "+std::to_string(number));//print the instruction line
        function_call(label,number);
    }
    else if (command == "function")
    {
        functionName=label;
        output_assembler("// function "+label+" "+std::to_string(number));//print the instruction line
        output_assembler("("+label+")");
        for (int i = 0; i < number; ++i)
        {
            stack_push("constant",0);
        }
    }
    else
    {
        fatal_error(0,"// bad func - expected call, funciton\n") ; 
    }
            
    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// translate vm operator command into assembly language
static void translate_vm_stack(ast stack)
{
    // extract command specific info from the ast node passed in
    string command = get_vm_stack_command(stack) ;
    string segment = get_vm_stack_segment(stack) ;
    int number = get_vm_stack_offset(stack) ;
    string La;

    // tell the output system what kind of VM command we are now trying to implement
    start_of_vm_stack_command(command,segment,number) ;

    /************   ADD CODE BETWEEN HERE   **************/

    // use the output_assembler() function to implement this VM command in Hack Assembler
    // careful use of helper functions you can define above will keep your code simple
    // ...
    //La = Classna;
    if (command == "push")
    {
        output_assembler("// "+command+" "+segment+" "+std::to_string(number));
        stack_push(segment, number);

    }
    else if (command == "pop")
    {
        output_assembler("// "+command+" "+segment+" "+std::to_string(number));
        stack_pop(segment, number, La);
    }
    else{
        fatal_error(0,"// bad stack - expected push, pop\n") ; 
    }


    /************         AND HERE          **************/

    // tell the output system that we have just finished trying to implement a VM command
    end_of_vm_command() ;
}

// main program
int main(int argc,char **argv)
{
    string Classna;

    std::vector<string> cus;
    // parse abstract syntax tree and pass to the translator
    translate_vm_class(ast_parse_xml()) ;

    // flush output and errors
    print_output() ;
    print_errors() ;
}
