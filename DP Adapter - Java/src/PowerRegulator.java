class PowerRegulator {  // Used by FuelCell

	class Ackumulator {

	  public Ackumulator() {
		charging=false;
	  }

	  public void charge() {
		  charging=true;
	  }

	  boolean hasPower()  {
		  return charging;
	  }

	  private boolean charging;

	}


  public PowerRegulator() {
     theBattery = new Ackumulator();
     power = 0;
  }

  public boolean setElectricPower(int p) {
     if(p<0 || p>100)
       return false;
     power = p;
     System.out.println("Electric power set to " +  power);
     return true;
  }

  public int getElectricPower()  {
     return power;
  }


  public void chargeBattery() {
	  theBattery.charge();
  }

  public boolean hasPower() {
	  return theBattery.hasPower();
  }

  private Ackumulator theBattery;
  private int power; // 0 .. 100 units

}