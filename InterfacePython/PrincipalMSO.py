from tkinter import *
window=Tk()
# titulos
window.title('UTN-CristianPadilla MSO Vehículo Autónomo')
window.geometry("900x600+10+20")
#btn=Button(window, text="Reporte", fg='black')
#btn.place(x=800, y=500)
lbl=Label(window, text="Universidad Técnica del Norte", fg='red', font=("Helvetica", 24))
lbl.place(x=30, y=20)
lbl=Label(window, text="Trabajo de titulación-Cristian Padilla", fg='black', font=("Helvetica", 18))
lbl.place(x=30, y=60)
##Labels Nodos
####NODO-A
lbl=Label(window, text="NODO-A", fg='black', font=("Helvetica", 18))
lbl.place(x=90, y=120)
lbl=Label(window, text="Posición Actual", fg='black', font=("Helvetica", 15))
lbl.place(x=90, y=170)
lbl=Label(window, text="Latitud", fg='black', font=("Helvetica", 13))
lbl.place(x=120, y=200)
lbl=Label(window, text="Longitud", fg='black', font=("Helvetica", 13))
lbl.place(x=120, y=230)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=230, y=200)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=230, y=230)
lbl=Label(window, text="Posición futura: - , -", fg='black', font=("Helvetica", 15))
lbl.place(x=90, y=260)
lbl=Label(window, text="Estado de Movimiento", fg='black', font=("Helvetica", 13))
lbl.place(x=120, y=290)
btn=Button(window,text="                  ",bg='red')
btn.place(x=300, y=290)
lbl=Label(window, text="ZANJA #: ", fg='black', font=("Helvetica", 15))
lbl.place(x=90, y=340)
lbl=Label(window, text="8", fg='darkblue', font=("Helvetica", 15))
lbl.place(x=200, y=340)
lbl=Label(window, text="Distancia Recorrido 1", fg='black', font=("Helvetica", 13))
lbl.place(x=55, y=370)
lbl=Label(window, text="Distancia Recorrido 2", fg='black', font=("Helvetica", 13))
lbl.place(x=55, y=400)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=230, y=370)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=230, y=400)
lbl=Label(window, text="RECORRIDO FACTIBLE: ", fg='black', font=("Helvetica", 15))
lbl.place(x=90, y=450)
lbl=Label(window, text="1", fg='darkblue', font=("Helvetica", 32))
lbl.place(x=200, y=490)
####NODO-B
lbl=Label(window, text="NODO-B", fg='black', font=("Helvetica", 18))
lbl.place(x=550, y=120)
lbl=Label(window, text="Posición Actual", fg='black', font=("Helvetica", 15))
lbl.place(x=550, y=170)
lbl=Label(window, text="Latitud", fg='black', font=("Helvetica", 13))
lbl.place(x=580, y=200)
lbl=Label(window, text="Longitud", fg='black', font=("Helvetica", 13))
lbl.place(x=580, y=230)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=690, y=200)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=690, y=230)
lbl=Label(window, text="Posición futura: - , -", fg='black', font=("Helvetica", 15))
lbl.place(x=550, y=260)
lbl=Label(window, text="Estado de Movimiento", fg='black', font=("Helvetica", 13))
lbl.place(x=580, y=290)
btn=Button(window,text="                  ",bg='red')
btn.place(x=760, y=290)
lbl=Label(window, text="ZANJA #: ", fg='black', font=("Helvetica", 15))
lbl.place(x=550, y=340)
lbl=Label(window, text="2", fg='darkblue', font=("Helvetica", 15))
lbl.place(x=660, y=340)
lbl=Label(window, text="Distancia Recorrido 1", fg='black', font=("Helvetica", 13))
lbl.place(x=515, y=370)
lbl=Label(window, text="Distancia Recorrido 2", fg='black', font=("Helvetica", 13))
lbl.place(x=515, y=400)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=690, y=370)
txtfld=Entry(window, text="", bd=5)
txtfld.place(x=690, y=400)
lbl=Label(window, text="RECORRIDO FACTIBLE: ", fg='black', font=("Helvetica", 15))
lbl.place(x=550, y=450)
lbl=Label(window, text="1", fg='darkblue', font=("Helvetica", 32))
lbl.place(x=660, y=490)



window.mainloop()