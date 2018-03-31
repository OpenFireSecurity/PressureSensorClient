public class Main{

    private static ArduinoPort arduinoPort;

    public static void main(String[] args) throws Exception {
        arduinoPort = new ArduinoPort();
        arduinoPort.initialize();
    }



}
