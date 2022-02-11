using System;
using SFML.Graphics;

namespace Aula4
{
    class Program
    {
        static void Main(string[] args)
        {

            uint windowWidth = 800, windowHeight = 600;

            RenderWindow window = new RenderWindow(new SFML.Window.VideoMode(windowWidth, windowHeight), "SFML.NET works in ubuntu too!");

            CircleShape circleShape = new CircleShape(50);

            circleShape.FillColor = Color.Magenta;
            circleShape.Position = new SFML.System.Vector2f(100,100);


            while(window.IsOpen)
            {
                window.Clear(new Color(64,64,64));
                window.Draw(circleShape);
                window.Display();
            }

            Console.WriteLine("Hello World!");
        }
    }
}
