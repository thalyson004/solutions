nadadorA = int( input() )
nadadorB = int( input() )
nadadorC = int( input() )

if (nadadorA < nadadorB) and (nadadorA < nadadorC):
    print("1")
    if nadadorB < nadadorC:
        print("2\n3")
    else:
        print("3\n2")
elif (nadadorB < nadadorA) and (nadadorB < nadadorC):
        print("2")
        if nadadorA < nadadorC:
            print("1\n3")
        else:
            print("3\n1")
else:
    print("3")
    if nadadorA < nadadorB:
        print("1\n2")
    else:
        print("2\n1")