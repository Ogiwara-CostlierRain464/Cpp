using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;


namespace Project1
{
    class md3d1:Form
    {
        const int Height = 600;
        const int Width = 800;

        public md3d1() : base()
        {
            MinimumSize = new Size(60,60);
            MaximizeBox = false;
            ClientSize = new Size(Width,Height);
            Text = "3D";
        }
    }

    class Program
    {
        public static void Main()
        {
            using (md3d1 dxform = new md3d1())
            {
                dxform.Show();
                while (dxform.Created)
                {
                    Application.DoEvents();
                }
            }
        }
    }
}
