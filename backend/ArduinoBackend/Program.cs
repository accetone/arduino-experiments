using ArduinoBackend.Experiments;
using ArduinoBackend.Proxy;

namespace ArduinoBackend
{
    class Program
    { 
        static void Main(string[] args)
        {
            IArduinoProxy proxy = new SerialProxy("COM3", 9600);

            var experiment = new LedUsb(proxy);
            experiment.Run();
        }
    }
}
