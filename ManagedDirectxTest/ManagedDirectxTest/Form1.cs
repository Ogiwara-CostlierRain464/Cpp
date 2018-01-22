using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace ManagedDirectxTest
{
    public partial class Form1 : Form
    {
        const int clientHeight = 600;
        const int clientWight = 800;

        public Form1():base()
        {
            InitializeComponent();
            MinimumSize = new Size(60,60);
            Text = "DirectX3D-My";
        }
    }
}
