class FuelCell {

  public FuelCell() {
      regulator = new PowerRegulator();
      active = false;
  }

  public void fuelOn() {
     if(active)
        return;
     active=true;
     regulator.chargeBattery();
     System.out.println("Fuelcell active and charging");
  }

  public void fuelOff() {
     active=false;
     System.out.println("Fuelcell inactive");
  }

  // returns a reference to the FuelCell's PowerRegulator
  public PowerRegulator getRegulator() {
	  return regulator;
  }

  public boolean isActive()  {
     return active;
  };


  private boolean active;
  private PowerRegulator regulator;

}