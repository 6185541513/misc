public class PowerSourceTest{

	public PowerSourceTest() {
		vector[0] = new XV8Classic();
		vector[1] = new XGasTurbine();
		vector[2] = new XFuelCell();
	}

	public void run() {
		for(PowerSource ps : vector){
			System.out.println(ps.toString());
			ps.tryStart();
			ps.incPower(10);
			ps.decPower(5);
			ps.stop();
		}
	}


	private PowerSource[] vector = new PowerSource[3];   

/*V8 CLASSIC*/
	class XV8Classic implements PowerSource{
		V8Classic inner = new V8Classic();
		
		@Override
		public boolean isRunning() {
			return inner.isRunning();
		}

		@Override
		public boolean tryStart() {
			inner.ignitionOn();
			inner.chokeOn();
			inner.setThrottle(30);
			inner.runStarter();inner.chokeOff();
			return isRunning();
		}

		@Override
		public boolean stop() {
			inner.setThrottle(0);
			inner.ignitionOff();
			return !isRunning();
		}

		@Override
		public boolean incPower(int p) {
			return inner.setThrottle(inner.getThrottle()+p);
		}

		@Override
		public boolean decPower(int p) {
			return inner.setThrottle(inner.getThrottle()-p);
		}
		
		public String toString(){
			return "**************\n"
					+ "* V8 Classic *\n"
					+ "**************";
		}
	}

/*GAS TURBINE*/
	class XGasTurbine implements PowerSource{
		GasTurbine inner = new GasTurbine();
		
		@Override
		public boolean isRunning() {
			return inner.running();
		}
	
		@Override
		public boolean tryStart() {
			inner.startCompressors();
			inner.setCompressorPressure(20);
			return inner.burnerOn();
		}
	
		@Override
		public boolean stop() {
			inner.setCompressorPressure(0);
			inner.stopCompressors();
			return inner.burnerOff();
		}
	
		@Override
		public boolean incPower(int p) {
			return inner.setCompressorPressure(inner.getCompressorPressure()+p);
		}
	
		@Override
		public boolean decPower(int p) {
			return inner.setCompressorPressure(inner.getCompressorPressure()-p);
		}
		
		public String toString(){
			return "\n\n***************\n"
					+ "* Gas Turbine *\n" 
					+ "***************";
		}
	}
	
/*FUEL CELL*/
	class XFuelCell implements PowerSource{
		FuelCell inner = new FuelCell();

		@Override
		public boolean isRunning() {
			return inner.isActive();
		}
	
		@Override
		public boolean tryStart() {
			inner.fuelOn();
			return isRunning();
		}
	
		@Override
		public boolean stop() {
			inner.getRegulator().setElectricPower(0);
			inner.fuelOff();
			return !isRunning();
		}
	
		@Override
		public boolean incPower(int p) {
			return inner.getRegulator().setElectricPower(inner.getRegulator().getElectricPower()+p);
		}
	
		@Override
		public boolean decPower(int p) {
			return inner.getRegulator().setElectricPower(inner.getRegulator().getElectricPower()-p);
		}
		
		public String toString(){
			return "\n\n*************\n"
					+ "* Fuel Cell *\n"
					+ "*************";
		}
	}
	
	public static void main(String args[]) {
		PowerSourceTest pst = new PowerSourceTest();
		pst.run();
	}
}