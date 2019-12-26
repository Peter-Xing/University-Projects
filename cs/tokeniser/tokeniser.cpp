// a skeleton implementation of a tokeniser

#include "tokeniser.h"
#include <iostream>
#include <ctype.h>

// to shorten the code
using namespace std ;

////////////////////////////////////////////////////////////////////////

namespace Assignment_Tokeniser
{

    // is the token of the given kind or does it belong to the given grouping?
    bool token_is_in(Token token,TokenKind kind_or_grouping)
    {
        TokenKind kind = token_kind(token) ;

        // check identity first
        if ( kind == kind_or_grouping ) return true ;

        // this is best written as nested switch statements
        switch(kind_or_grouping)
        {
        default:
            return false ;
        }
    }

    // the current input character, initiliased to ' ' which we ignore
    // the eof marker can be confused with a legal character but not one accepted by our tokeniser
    static char ch = ' ' ;

    // the current line number and column, initialised to line 1 column 0
    static int line_num = 1 ;
    static int column_num = 0 ;

    // the line number and column for the first character in the current token
    static int start_line = 0 ;
    static int start_column = 0 ;

    // generate a context string for the given token
    // it shows the line before the token,
    // the line containing the token up to the end of the token, and
    // a line with a ^ marking the token's position
    // the lines are prefixed by line numbers, right justified in four spaces, followed by ': '
    // if a token extends over more than one line, only the part of the token on the first line is included
    string token_context(Token token)
    {
        return "" ;
    }

    // read next character if not at the end of input
    // and update the line and column numbers
    static void nextch()
    {
        if ( ch == EOF ) return ;

        if ( ch == '\n' )           // if last ch was newline ...
        {
            line_num++ ;            // increment line number
            column_num = 0 ;        // reset column number
        }

        
        
        ch = read_char() ;          // read the next character, probably from stdin but this could change during testing
        column_num++ ;              // increment the column number
        
        if (ch == '\t')
        {
            ch = ' ';
            column_num = column_num+3;
        }
        if (ch=='\r')
        {
            column_num=0;
            nextch();
        }
        
                                    // additional code will be required here to handle preprocessing of '\t' and '\r'
                                    // you should also consider building a line by line copy of the input for use by token_context()
    }

    ////////////////////////////////////////////////////////////////////////

    // called when we find end of input or we an error
    Token parse_eoi()
    {
        // simulate end of input in case this is handling a bad token rather than a real end of input
        ch = EOF ;

        // return an eoi token
        return new_token(tk_eoi,"",start_line,start_column) ;
    }


    // does the given kind belong to the given grouping?
    bool token_kind_is_in(TokenKind kind,TokenKind kind_or_grouping)
    {   
        // check identity first
        if ( kind == kind_or_grouping ) return true ;
        
        // this is best written as nested switch statements
        switch(kind_or_grouping)
        {   
        default:
           return false ;
        }   
    }   

    //identifier
    static Token parse_identifier(TokenKind kind,string spelling)
    {

        // append alnum to spelling until we read past the end of the identifier
        while ( isalnum(ch) || isdigit(ch) || ch == '_' || ch =='$'||ch=='.')
        {
            spelling += ch ;
            nextch() ;
        }


        TokenKind id_or_kw = string_to_token_kind(spelling) ;
/*        if ( !token_kind_is_in(id_or_kw,tk_keyword) ){
            id_or_kw = tk_identifier ;
            return new_token(id_or_kw,spelling,start_line,start_column) ;
        } 
        else*/ if (id_or_kw==tk_do)
        {
            return new_token(tk_do,spelling,start_line,start_column);
        }
        else if (id_or_kw==tk_for)
        {
            return new_token(tk_for,spelling,start_line,start_column);
        }
        else if (id_or_kw==tk_pointer)
        {
            return new_token(tk_pointer,spelling,start_line,start_column);
        }
        else if (id_or_kw==tk_real)
        {
            return new_token(tk_real,spelling,start_line,start_column);
        }
        else if (id_or_kw==tk_this)
        {
            return new_token(tk_this,spelling,start_line,start_column);
        }
        else
        {
            return new_token(kind,spelling,start_line,start_column) ;
        }
    }

    // parse a number - always read one extra character
    // we know spelling is the first digit of the number
    static Token parse_integer(TokenKind kind,string spelling)
    {
        //initialize a new string for float
        string f = "";
        // append digits to spelling until we read past the end of the integer
        while ( isdigit(ch) )
        {
            spelling += ch ;
            nextch() ;
        }

        //check if it is float, fraction exponent?
        if (ch=='.')
        {   //add the . to string
            f = f + spelling;
            f+=ch;
            nextch();
            if (!isdigit(ch)&&ch!='e'&&ch!='E')
            {
                f=f+'0';
                f=f+'e';
                f=f+'+';
                f=f+'0';
                //output here
                return new_token(tk_float,f,start_line,start_column) ;
            }
            else if (!isdigit(ch))
            {
                f=f+'0';
            }
            while( isdigit(ch) )
            {   //add 0 or more 0-9 to string
                f += ch ;
                nextch() ;
            }
            //the exponent after fraction
            if(ch=='e'||ch=='E')
            {
            //add e or E 
                f+='e';
                nextch();
                if (ch=='+'||ch=='-')
                {
                //add + or - if there is any
                    f+=ch;
                    nextch();
                    if(ch=='0')
                    {   //add 0
                        f+=ch;
                        nextch();
                    }
                    else if (ch>='1'&&ch<='9')
                    {   //add 1-9 along with o or more 0-9
                        f+=ch;
                        nextch();
                        while( isdigit(ch) )
                        {   //add 0 or more 0-9 to string
                            f += ch ;
                            nextch() ;
                        }   
                    }
                }
                else if(ch=='0')
                {   //add 0
                    f+='+';
                    f+=ch;
                    nextch();
                }
                else if (ch>='1'&&ch<='9')
                {   //add 1-9 along with o or more 0-9
                    f+='+';
                    f+=ch;
                    nextch();
                    while( isdigit(ch) )
                    {   //add 0 or more 0-9 to string
                        f += ch ;
                        nextch() ;
                    }
                }
                else{
                    f+='+';
                    nextch();
                }
            }
            else if(ch!='e'&&ch!='E')
            {
                f+='e';
                f+='+';
                f+='0';
            }
            return new_token(tk_float,f,start_line,start_column) ;
        }

        //check if it is exponent
        else if(ch=='e'||ch=='E')
        {
            //add e or E 
            f = f + spelling;
            f+='e';
            nextch();
            if (ch=='+'||ch=='-')
            {
                //add + or - if there is any
                f+=ch;
                nextch();
                if(ch=='0')
                    {   //add 0
                        f+=ch;
                        nextch();
                    }
                    else if (ch>='1'&&ch<='9')
                    {   //add 1-9 along with o or more 0-9
                        f+=ch;
                        nextch();
                        while( isdigit(ch) )
                        {   //add 0 or more 0-9 to string
                            f += ch ;
                            nextch() ;
                        }   
                    }
            }
            else if(ch=='0')
            {   //add 0
                f+='+';
                f+=ch;
                nextch();
            }
            else if (ch>='1'&&ch<='9')
            {   //add 1-9 along with o or more 0-9
                f+='+';
                f+=ch;
                nextch();
                while( isdigit(ch) )
                {   //add 0 or more 0-9 to string
                  f += ch ;
                  nextch() ;
                }
            }
            else{
                    f+='+';
                    nextch();
                }

            return new_token(tk_float,f,start_line,start_column) ;
        }
  /*      else if(ch!='e'&&ch!='E')
            {
                f+='e';
                f+='+';
                f+='0';
               
            }
    */    else{

            // return a new Token object
            return new_token(kind,spelling,start_line,start_column) ; 
        } 
    }

    // when we read 0
    static Token parse_zero(TokenKind kind,string spelling)
    {
        spelling+=ch;
        nextch();
        string f = "";

        //check if it is a float
        if (ch=='.')
        {   //add the . to string
            f = f + spelling;
            f+=ch;
            nextch();
            if (!isdigit(ch)&&ch!='e'&&ch!='E')
            {
                f=f+'0';
                f=f+'e';
                f=f+'+';
                f=f+'0';
                //output here
                return new_token(tk_float,f,start_line,start_column) ;
            }
            else if (!isdigit(ch))
            {
                f=f+'0';
            }
            while( isdigit(ch) )
            {   //add 0 or more 0-9 to string
                f += ch ;
                nextch() ;
            }
            if(ch=='e'||ch=='E')
            {
            //add e or E 
                f+='e';
                nextch();
                if (ch=='+'||ch=='-')
                {
                //add + or - if there is any
                    f+=ch;
                    nextch();
                    if(ch=='0')
                    {   //add 0
                        f+=ch;
                        nextch();
/*                        while( isdigit(ch) )
                        {   //add 0 or more 0-9 to string
                            f += ch ;
                            nextch() ;
                        }                     */
                    }
                    else if (ch>='1'&&ch<='9')
                    {   //add 1-9 along with o or more 0-9
                        f+=ch;
                        nextch();
                        while( isdigit(ch) )
                        {   //add 0 or more 0-9 to string
                            f += ch ;
                            nextch() ;
                        }   
                    }
                }
                else if(ch=='0')
                {   //add 0
                    f+='+';
                    f+=ch;
                    nextch();
                }
                else if (ch>='1'&&ch<='9')
                {   //add 1-9 along with o or more 0-9
                    f+='+';
                    f+=ch;
                    nextch();
                    while( isdigit(ch) )
                    {   //add 0 or more 0-9 to string
                        f += ch ;
                        nextch() ;
                    }
                }
                else{
                    f+='+';
                    nextch();
                }
            }
            else if(ch!='e'&&ch!='E')
            {
                f+='e';
                f+='+';
                f+='0';
                
            }
            return new_token(tk_float,f,start_line,start_column) ;
        }

        //check if it is exponent
        else if(ch=='e'||ch=='E')
        {
            //add e or E 
            f = f + spelling;
            f+='e';
            nextch();
            if (ch=='+'||ch=='-')
            {
                //add + or - if there is any
                f+=ch;
                nextch();
                if(ch=='0')
                    {   //add 0
                        f+=ch;
                        nextch();
                    }
                    else if (ch>='1'&&ch<='9')
                    {   //add 1-9 along with o or more 0-9
                        f+=ch;
                        nextch();
                        while( isdigit(ch) )
                        {   //add 0 or more 0-9 to string
                            f += ch ;
                            nextch() ;
                        }   
                    }
            }
            else if(ch=='0')
            {   //add 0
                f+='+';
                f+=ch;
                nextch();
            }
            else if (ch>='1'&&ch<='9')
            {   //add 1-9 along with o or more 0-9
                f+='+';
                f+=ch;
                nextch();
                while( isdigit(ch) )
                {   //add 0 or more 0-9 to string
                  f += ch ;
                  nextch() ;
                }
            }
            else{
                    f+='+';
                    nextch();
                }
            return new_token(tk_float,f,start_line,start_column) ;
        }
 /*       else if(ch!='e'&&ch!='E')
            {
                f+='e';
                f+='+';
                f+='0';
            }
   */     else{

            // return a new Token object
            return new_token(kind,spelling,start_line,start_column) ; 
        } 
    }

    //when the number is float
   //  static Token parse_float(TokenKind kind,string spelling)
 //   {
       
        // append until the end of string
 //       while ( ch == )
  //      {
//            spelling += ch ;
//            nextch() ;
//        }
       
        // return a new Token object
//        return new_token(kind,spelling,start_line,start_column) ;
  //  }

    //parse a string
    // start with " and end with"
    // things inside are in spelling
    static Token parse_string(TokenKind kind,string spelling)
    {
        //next ch is the start of the string
        nextch();
        // append until the end of string
        while ( ch == ' '||ch=='!'||(ch >='#'&&ch<='~') )
        {
            spelling += ch ;
            nextch() ;
        }
        //we need to ignore the last " ,so when ch becomes " again, we just move to next ch
        if(ch == '"'){
            nextch();
        }
        // return a new Token object
        return new_token(kind,spelling,start_line,start_column) ;
    }

    // parse a single character symbol
    // we know spelling is the one character symbol
    // the caller already knows the kind and spelling so they are passed as parameters
    // if they were not we would have to repeat the switch statement to find out
    static Token parse_single_char_symbol(TokenKind kind,string spelling)
    {

        //if it is the eol_comment go to the eol function
        if (ch == '/')
        {
            

            spelling+=ch;
            nextch();
            if (ch=='/')
            {
                nextch();
                string ss = "";
                while(ch>=' '&& ch<='~')
                {
                    ss+=ch;
                    nextch();
                }
                
                return new_token(tk_eol_comment,ss,start_line,start_column);
            }
            else if (ch=='*')
            {
                nextch();
                string s2 = "";
                while(ch>=' '&& ch<='~'||ch=='\n')
                {
                    s2+=ch;
                    nextch();
                }
                if (ch=='*')
                {
                    nextch();
                    if (ch=='/')
                    {
                        nextch();
                    }
                }

                return new_token(tk_adhoc_comment,s2,start_line,start_column);
            }

            else{
               
                return new_token(kind,spelling,start_line,start_column);
            }
        }


        spelling += ch;
        // always read the next character - we have read past the end of the token
        nextch() ;

        // return a new Token object
        return new_token(kind,spelling,start_line,start_column) ;
    }

     
     


    static Token parse_multiple_char_symbol(TokenKind kind,string spelling)
    {
        if (ch == '=')
        {    
            spelling += ch;
            nextch();
            if (ch == '=')
            {
                spelling += ch;
                nextch();
                return new_token(kind, spelling, start_line, start_column);
            }else{
                return parse_eoi();
            }
        }

        if (ch == '<')
        {
            spelling+=ch;
            nextch();
            if (ch == '=')
            {
                spelling += ch;
                nextch();
                if (ch == '>')
                {
                    spelling += ch;
                    nextch();
                    return new_token(kind, spelling, start_line, start_column);
                }else{
                    return parse_eoi();
                }
            }
        }


    }
    


    // return the next token object by reading more of the input
    Token next_token()
    {
        // you must read input using the nextch() function
        // the last character read is in the static variable ch
        // always read one character past the end of the token being returned

        string spelling = "" ;

        // this loop reads one character at a time until it reaches end of input
        while ( ch != EOF )
        {
            start_line = line_num ;                 // remember current position in case we find a token
            start_column = column_num ;

            switch(ch)                              // ch is always the next char to read
            {
            case ' ':                               // ignore space and newline
            case '\n':
                nextch() ;                          // read one more character and try again
                break ;
                                                    // add additional case labels here for characters that can start tokens
                                                    // call a parse_*(kind,spelling) function to complete and return each kind of token
                                                    // this should follow the style used in the workshops
                                                    // but remember that the token grammar is different in this assignment
            case '0':       return parse_zero(tk_integer,spelling); 
            case '1'...'9': return parse_integer(tk_integer,spelling);  

            case 'a'...'z':
            case 'A'...'Z': 
            case '_':       return parse_identifier(tk_identifier, spelling);  



            case '@':       return parse_single_char_symbol(tk_at,spelling);
            case '{':       return parse_single_char_symbol(tk_lcb,spelling) ;
            case '}':       return parse_single_char_symbol(tk_rcb,spelling) ;
            case '(':       return parse_single_char_symbol(tk_lrb,spelling) ;
            case ')':       return parse_single_char_symbol(tk_rrb,spelling) ;
            case '[':       return parse_single_char_symbol(tk_lsb,spelling) ;
            case ']':       return parse_single_char_symbol(tk_rsb,spelling) ;
            case '/':       return parse_single_char_symbol(tk_div,spelling) ;
            case ':':       return parse_single_char_symbol(tk_colon,spelling) ;
            case ';':       return parse_single_char_symbol(tk_semi,spelling) ;
            case '!':       return parse_single_char_symbol(tk_not,spelling) ;
            case '.':       return parse_single_char_symbol(tk_stop,spelling) ;
            case ',':       return parse_single_char_symbol(tk_comma,spelling) ;
            case '=':       return parse_multiple_char_symbol(tk_eq,spelling) ;
            case '<':       return parse_multiple_char_symbol(tk_spaceship,spelling) ;
            
            case '"':       return parse_string(tk_string,spelling);
                  
            default:
                return parse_eoi() ;                // the next character cannot start a token, this is an error, return an EOI token
            }
        }

        start_line = line_num ;                     // remember current position so EOI token is correct
        start_column = column_num ;

        return parse_eoi() ;                         // return an EOI token
    }
}
