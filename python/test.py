
import tkinter as tk
import os
from tkinter import filedialog as fd

class MyApp(tk.Frame):  
    
        
    def __init__(self, master = None):
        super().__init__(master)
        
        self.master.geometry('400x400')
        
        self.master.title('110502516, 109202505')
        
        self.MyLabel1 = tk.Label(self.master)
        self.MyLabel1.pack()
        
        self.MyButton1 = tk.Button(self.master, text='Open file', command = self.button_event)
        self.MyButton1.pack()
        
    def button_event(self):
        f = fd.askopenfilename()
        
        self.MyLabel1['text'] = os.path.basename(f)
    
    

# create the root window
root = tk.Tk()
app = MyApp(master = root)
app.mainloop()