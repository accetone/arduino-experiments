namespace ArduinoBackend.Proxy
{
    public interface IArduinoProxy
    {
        void Write(string data);
        string Read();
    }
}
