class GasTurbine {

  public GasTurbine() {
	  		pressure=0;
	  		isRunning=false;
      		compressors=false;
      		burner=false;
         }

  public boolean startCompressors() {
    if(isRunning)
      return false;
    System.out.println("Compressors started");
    compressors = true;
    checkRunning();
    return true;
  }

  public boolean stopCompressors() {
    if(!compressors)
      return false;
    System.out.println("Compressors stopped");
    compressors = false;
    checkRunning();
    return true;
  }

  public boolean burnerOn() {
    if(isRunning || pressure==0)
      return false;
    System.out.println("Burner started");
    burner = true;
    checkRunning();
    return true;
  }

  public boolean burnerOff() {
    if(!burner)
      return false;
    System.out.println("Burner stopped");
    burner = false;
    checkRunning();
    return true;
  }

  public boolean setCompressorPressure(int p) {
    if(p<0 || p>100 ||!compressors)
      return false;

    pressure = p;
    System.out.println("Pressure is " + pressure + " units");
    return true;
  }


  public int getCompressorPressure() {

      return pressure;
  }

  public boolean running()  {
    return isRunning;
  }

  private void checkRunning() {
    isRunning = pressure>0 && compressors && burner;
  }

  private int pressure; // 0 .. 100 units
  private boolean isRunning, compressors, burner;

}