
public abstract class Electric extends Vehicle{
	protected float kpW;

	Electric(){
		super();
	}

	Electric(float kpW){
		super();
		this.kpW = kpW;
	}

	public void move(float kpL, float power, float fuel){
	};
}
