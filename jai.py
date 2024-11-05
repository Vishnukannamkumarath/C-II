import tkinter as tk
from tkinter import messagebox
from datetime import datetime

def calculate_age():
    try:
        birth_date = datetime.strptime(entry_birth_date.get(), '%Y-%m-%d')
        today = datetime.today()
        age = today.year - birth_date.year - ((today.month, today.day) < (birth_date.month, birth_date.day))
        messagebox.showinfo("Age", f"You are {age} years old.")
    except ValueError:
        messagebox.showerror("Invalid Date", "Please enter the date in YYYY-MM-DD format.")

# Create the main window
root = tk.Tk()
root.title("Age Calculator")

# Create and place the widgets
label = tk.Label(root, text="Enter your birth date (YYYY-MM-DD):")
label.pack(pady=10)

entry_birth_date = tk.Entry(root)
entry_birth_date.pack(pady=10)

button_calculate = tk.Button(root, text="Calculate Age", command=calculate_age)
button_calculate.pack(pady=20)

# Run the application
root.mainloop()

