using System;
using ArduinoBackend.Proxy;

namespace ArduinoBackend.Experiments
{
    /// <summary>
    /// Usage: 
    /// 
    /// var proxy = new SerialProxy("COM3", 9600);
    /// 
    /// var experiment = new LedUsb(proxy);
    /// LedUsb.Run();
    /// 
    /// </summary>
    public class LedUsb : IExperiment
    {
        private int _ledsCount;

        public int LedsCount
        {
            get { return _ledsCount; }
            set { if (value > 0) _ledsCount = value; }
        }

        public IArduinoProxy Proxy { get; set; }

        public LedUsb(IArduinoProxy proxy)
        {
            Proxy = proxy;
            LedsCount = 5;
        }

        public void Run()
        {
            string input;
            int led, signal;

            while (true)
            {
                Console.Clear();

                Console.WriteLine($"Send signal to led (1-{LedsCount})");
                input = Console.ReadLine();

                if (!int.TryParse(input, out led) || led < 0 || led > LedsCount)
                {
                    Console.WriteLine("Incorrect input");
                    Console.WriteLine("Press any key to continue");
                    Console.ReadKey();

                    continue;
                }

                Console.Clear();

                Console.WriteLine($"What signal send to led #{led}: switch off (0) or switch on (1)");
                input = Console.ReadLine();

                if (!int.TryParse(input, out signal) || signal < 0 || signal > 1)
                {
                    Console.WriteLine("Incorrect input");
                    Console.WriteLine("Press any key to continue");
                    Console.ReadKey();

                    continue;
                }

                Proxy.Write($"{led - 1} {signal}");

                Console.Clear();
                Console.WriteLine("Sent");
                Console.WriteLine("Press any key to continue");
                Console.ReadKey();
            }
        }
    }
}
