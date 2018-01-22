using System.Windows.Forms;
using System.Drawing;

namespace ManagedDirectxTest
{
    /// <summary>
    /// md3d1 の概要の説明です。
    /// </summary>
    public class Form1 : Form
    {
        //クライアント領域のサイズ
        const int clientHeight = 600;
        const int clientWight = 800;

        public md3d1() : base()
        {
            //最小サイズを設定
            this.MinimumSize = new Size(60, 60);

            //下は任意です。

            //固定サイズのフォーム（任意、これを付けるとサイズが変わらなくなる）
            //this.FormBorderStyle = FormBorderStyle.FixedSingle;
            //サイダかボタン無し
            this.MaximizeBox = false;
            //クライアント領域サイズ
            this.ClientSize = new Size(clientWight, clientHeight);
            //ウィンドウの名前(かっこいいのを付けてあげてください）
            this.Text = "Direct3D-My";
        }
    }

    /// <summary>
    /// エントリクラス
    /// </summary>
    class Program
    {
        public static void Main()
        {
            Application.Run(new md3d1());
        }
    }
}

