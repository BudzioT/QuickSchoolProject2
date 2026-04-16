namespace Desktop2025
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        private void HandleRSlider(object? sender, EventArgs e)
        {
            HandleSliders(0);
        }

        private void HandleGSlider(object? sender, EventArgs e)
        {
            HandleSliders(1);
        }

        private void HandleBSlider(object? sender, EventArgs e)
        {
            HandleSliders(2);
        }

        private void HandleSliders(int colorId)
        {
            if (SliderR == null || SliderG == null || SliderB == null)
            {
                return;
            }
            int r = (int)SliderR.Value;
            int g = (int)SliderG.Value;
            int b = (int)SliderB.Value;

            LabelR.Text = r.ToString();
            LabelG.Text = g.ToString();
            LabelB.Text = b.ToString();

            RectangleColors.Fill = Color.FromRgb(r, g, b);
        }

        private void HandleButtonClick(object? sender, EventArgs e)
        {
            if (SliderR == null || SliderG == null || SliderB == null)
            {
                return;
            }
            int r = (int)SliderR.Value;
            int g = (int)SliderG.Value;
            int b = (int)SliderB.Value;

            LabelColor.BackgroundColor = Color.FromRgb(r, g, b);

            LabelColor.Text = $"{r}, {g}, {b}";
        }

        //private void OnCounterClicked(object? sender, EventArgs e)
        //{
        //    count++;

        //    if (count == 1)
        //        CounterBtn.Text = $"Clicked {count} time";
        //    else
        //        CounterBtn.Text = $"Clicked {count} times";

        //    SemanticScreenReader.Announce(CounterBtn.Text);
        //}
    }
}
