
public interface PowerSource {

   public boolean isRunning();
   public boolean tryStart();
   public boolean stop();
   public boolean incPower(int p);
   public boolean decPower(int p);
   public String toString();
}