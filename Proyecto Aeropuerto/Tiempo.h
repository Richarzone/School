using namespace std;
class Tiempo 
{
    public:
        Tiempo();
        Tiempo(int hora, int min);
        int getHora();
        int getMinuto();
        void setHora(int h);
        void setMinuto(int m);
    private:
        int hora, minuto;
};
Tiempo::Tiempo() {}
Tiempo::Tiempo(int hora, int min) : hora(hora), minuto(min) {}
int Tiempo::getHora() 
{
    return hora;
}
int Tiempo::getMinuto() 
{
    return minuto;
}
void Tiempo::setHora(int h) 
{
    hora = h;
}
void Tiempo::setMinuto(int m) 
{
    minuto = m;
}