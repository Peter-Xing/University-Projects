public class ComplexCalculator{
	private double a,b;//fields: real part and imaginary part

	//constructor
	ComplexCalculator(double a,double b){
		this.a=a;
		this.b=b;		
	}


	//the four arithmetic methods
	//addition of the two complex numbers is a+c+(b+d)*i
	public ComplexCalculator add(ComplexCalculator C){
		double a2=this.a+C.a;
		double b2=this.b+C.b;
		return new ComplexCalculator(a2,b2);
	}
	//subtraction of the two complex numbers is a-c+(b-d)*i
	public ComplexCalculator sub(ComplexCalculator C){
		double a2=this.a-C.a;
		double b2=this.b-C.b;
		return new ComplexCalculator(a2,b2);
	}
	//Multiplication is equal to (a*c-b*d)+(a*b+c*d)*i
	public ComplexCalculator multiplication(ComplexCalculator C){
		double a2=this.a*C.a-this.b*C.b;
		double b2=this.a*C.b+this.b*C.a;
		return new ComplexCalculator(a2,b2);
	}
	//Division is equal to (ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)*i
	public ComplexCalculator division(ComplexCalculator C){
		double a2=(this.a*C.a+this.b*C.b)/(C.a*C.a+C.b*C.b);
		double b2=(this.b*C.a-this.a*C.b)/(C.a*C.a+C.b*C.b);
		return new ComplexCalculator(a2,b2);
	}
	// test cases in here
	public static void main(String args[]){
		ComplexCalculator C1 = new ComplexCalculator(1,2);
		ComplexCalculator C2=new ComplexCalculator(1,-3);
		ComplexCalculator C3;
		C3=C1.add(C2);
		System.out.println(C3.a+"+ ("+C3.b+")*i");
		C3=C1.sub(C2);
		System.out.println(C3.a+"+ ("+C3.b+")*i");
		C3=C1.multiplication(C2);
		System.out.println(C3.a+"+ ("+C3.b+")*i");
		C3=C1.division(C2);
		System.out.println(C3.a+"+ ("+C3.b+")*i");
	}
}