i = input()
while i != "0:00":
    t = i.split(":")
    h = float(t[0])
    m = float(t[1])
    dh = (360.0*h)/12 + (360.0*m)/(12.0*60.0)
    dm = (360.0*m)/60
    diff = abs(dh - dm)
    if diff > 180:
        diff = 360 - diff
    print(f'{round(diff, 3):.3f}')
    i = input()