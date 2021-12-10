# Lop HTNLX HK201_CQ, thi HK
# Cau 1
# Matlab tinh goc theo rad!
import math

pi = math.pi

do_rad=pi/180
rad_do=180/pi
S=1 # sun
Tamb=29 # nhiet do moi truong, oC
Peak_Hour=4.2 # gio nang dinh /ngay
Psolar=1e6 # Wp
# PV panel
ncell=156 # cells
A=2.0 # m2
Pm=440 # W
Voc=51.7 # V
Vm=43.65 # V
Isc=10.77 # A
Im=10.08 # A
NOCT=40 # oC
TCIsc= 0.048 # #/oC
TCVoc=-0.28 # #/oC
TCPm=-0.35 # #/oC
Eff_array=0.97 # He so ghep mang
Eff_INV_a=0.975
print('Bai giai_________________')
Tcell=Tamb+(NOCT-20)/0.8*S
Isc_t = Isc*(1+TCIsc/100*(Tcell-25))
Voc_t=Voc*(1+TCVoc/100*(Tcell-25))
Voc_at0=Voc*(1+TCVoc/100*(0-25))
Pm_t=Pm*(1+TCPm/100*(Tcell-25))
print('Cau a_________________')
No_panel=math.floor(Psolar/Pm)
Pac_inv=No_panel*Pm_t*Eff_array*Eff_INV_a #sys = system
print('.) Tcell_a = #f [oC]', Tcell)
print('.) Isc_t = #f [A]', Isc_t)
print('.) Voc_t = #f [V]', Voc_t)
print('.) Voc_at0 = #f [V]', Voc_at0)
print('.) Pm_t = #f [W]', Pm_t)
print('Cau a____________________________________________________')
print('So luong tam pin: #f [panels]', No_panel)
print('Dien ap ho mach 1 panel o 0 do C: #f [V]', Voc_at0)
print('Dien ap ho mach Inverter là 1000V => Moi string chon 16 panels ghep noi tiep')
print('Tong so string la: #f [string ghep song song]', No_panel/16)
print('Dien ap lam viec o 25 do C: #f [V] < 850 Vdc', 16*Vm)
print('Dien ap ho mach moi string o 0 do C: #f [V] < 1000 Vdc', 16*Voc_at0)

print('Dong dien ngan mach tong: #f [A]', No_panel/16*Isc_t)
print('Cong suat inverter: > #f [kWac], chon Inverter 850 kWac', Pac_inv/1000) 

print('.')
print('Cau b____________________________________________________')
Pac_MAX=Pac_inv
E_year=Pac_MAX*Peak_Hour*365
print('b) Cong suat giua trua: #f MW', Pac_MAX/1e6)
print('b) San luong moi nam: #f GWh', E_year/1e9)
print('.')
print('Cau c____________________________________________________')
print('Moi nhom khong qua 40 x 40m: Dong Tay 16 panels = 32m+1.5=33.5m. Bac Nam 18 day = 18*(1+0.5) + 1.5=28m')
print('Dien tich moi nhom: 33.5*28 = 938 m2 + dien tich mang cap = ~1000 m2')
print('So nhom: 2272/(16*18) = ~8 nhom')
print('=> Dien tich toi thieu: 8 * 1000 = ~ 8000 m2')