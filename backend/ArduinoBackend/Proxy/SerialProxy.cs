using System;
using System.IO.Ports;

namespace ArduinoBackend.Proxy
{
    public class SerialProxy : IArduinoProxy
    {
        private readonly SerialPort _serialPort;

        public SerialProxy(string port, int baudRate)
        {
            _serialPort = new SerialPort(port, baudRate);
        }

        public void Write(string data)
        {
            _serialPort.Open();
            _serialPort.WriteLine(data);
            _serialPort.Close();
        }

        public string Read()
        {
            return "";
        }
    }
}
