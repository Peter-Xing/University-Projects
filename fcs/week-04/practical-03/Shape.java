class Shape{
	//attributes
	private double width;
	private double height;
	private double radius;
	private double length;

	//basic constructor
	Shape(){}

	//parametric constructor
	Shape(double a, double b, double c, double d){
		this.width = a;
		this.height = b;
		this.radius = c;
		this.length = d;
	}

	//accessors
	public double getWidth(){
		return this.width;
	}
	public double getHeight(){
		return this.height;
	}
	public double getRadius(){
		return this.radius;
	}
	public double getLength(){
		return this.length;
	}

	//mutators
	public void setWidth(double a){
		this.width = a;
	}
	public void setHeight(double b){
		this.height = b;
	}
	public void setRadius(double c){
		this.radius = c;
	}
	public void setLength(double d){
		this.length = d;
	}
}