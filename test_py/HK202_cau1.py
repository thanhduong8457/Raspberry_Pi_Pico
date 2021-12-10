# Lop NLTT HK202_CQ, Thi HK
# Cau 1
# Matlab tinh goc theo rad!
import math

do_rad=math.pi/180
rad_do=180/math.pi
S=1 # sun
Tamb=28 # nhiet do moi truong, oC
Peak_Hour=5 # gio nang dinh /ngay
pinv=800e3 # Wac
# PV panel
#ncell=2*78 # cells
Pm=475 # W
Voc=52.26 # V
Vm=43.38 # V
Isc=11.77 # A
Im=10.59 # A
TCIsc= 0.048 # #/oC
TCVoc=-0.28 # #/oC
TCPm=-0.35 # #/oC
NOCT=45 # oC
Eff_array=0.96 # He so ghep mang
Eff_1year=1.00 # Hieu suat sau 1 thoi gian su dung
Eff_inv=0.97
print('Bai giai_________________________________')
print('Cau a____________________________________')
Tcell=Tamb+(NOCT-20)/0.8*S
Pm_a=Eff_1year*Pm*(1+TCPm/100*(Tcell-25))
Pac_1string_MAX=16*Pm_a*Eff_array*Eff_inv
No_String=round(pinv/Pac_1string_MAX)
print('Cau b____________________________________')
P_inv_MAX=No_String*Pac_1string_MAX
E_1day=No_String*Pac_1string_MAX*Peak_Hour
print('Cau c____________________________________')
Pm_d=0.8*Eff_1year*Pm*(1+TCPm/100*(NOCT-25))
pinv_d=16*Pm_d*No_String*Eff_array*Eff_inv
print('Ket qua____________________________ ')
print('.) Tcell_a = #f [oC]', Tcell)
print('a) Cong suat cua 1 tam math.pin: #f [W]', Pm_a)
print('a) So luong string: #f [strings]', No_String)
print('b) San luong moi ngay: #f [MWh]', E_1day/1e6)
print(Pm_d)
print('c) Cong suat phat dien o NOCT: #f [kW]', pinv_d/1e3)