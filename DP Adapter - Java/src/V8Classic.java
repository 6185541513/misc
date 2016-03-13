class V8Classic  {

   public V8Classic() {
            running=false;
            ignition=false;
            choke=false;
            throttle=0;
          }

   public void ignitionOn() {
     ignition=true;
     System.out.println("ignition ON ");
   }

   public void ignitionOff() {
     ignition=false;
     running=false;
     System.out.println("ignition OFF ");
   }

   public void chokeOn() {
     choke=true;
     System.out.println("choke ON ");
   }

   public void chokeOff() {
     choke=false;
     System.out.println("choke OFF ");
   }

   public int getThrottle()  {
     return throttle;
   }

   public boolean setThrottle(int t) {
     if(t<0 || t>100)
       return false;
     throttle = t;
     System.out.println("Throttle is open " + throttle + " % ");
     return true;
   }

   public void runStarter() {
     if(running) {
       System.out.println("Already running");
       return;
     }
     System.out.println("Running starter...");
     if(ignition && choke && throttle>25) {
       running=true;
       System.out.println("The V8 is running");
     }
     else
       System.out.println("The V8 won't start.");
   }

   public boolean isRunning()  {
     return running;
   }


   private boolean running, ignition, choke;
   private int throttle; //throttle vent 0 .. 100 units
}