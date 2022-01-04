using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfApp6.Model;

namespace WpfApp6.ViewModel
{
    class MainViewModel : INotifyPropertyChanged
    {
        private MainModel myModel = null;

        public MainViewModel()
        {
            myModel = new MainModel();
            string n = Dollar;
            MessageBox.Show(n);
            
        }
        public string Dollar
        {
            get
            {
                if (string.IsNullOrEmpty(myModel.dollar))
                {
                    Won = "0";
                }
                else
                {
                    int num = -1;
                    if (int.TryParse(myModel.dollar, out num))
                    {
                        int result = num * 1160;
                        Won = result.ToString();
                    }
                    else
                    {
                        MessageBox.Show("Please insert number", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                        Dollar = "";
                        Won = "0";
                    }
                }
                return myModel.dollar;
            }
            set
            {
                if (myModel.dollar != value)
                {
                    myModel.dollar = value;
                    OnPropertyChanged("Dollar");
                }
            }
        }

        public string Won
        {
            get
            {
                return myModel.won;
            }
            set
            {
                myModel.won = value;
                OnPropertyChanged("Won");
            }
        }
        
       


        public event PropertyChangedEventHandler PropertyChanged;
        protected void OnPropertyChanged(string prop)
        { 
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
            }
        }
    }
}
