import serial
import time

# Connect to the XBee on the correct USB port
xb = serial.Serial('/dev/ttyUSB1', 9600)
print("XBee connected")
Data = [0, 0, 0]

while True:
    try:
        Input = xb.readline().decode('utf-8')
        print("Raw input:", Input)
        if Input:
            Data = Input.split(",")
            tempData = int(Data[0])
            humiData = int(Data[1])
            lightData = int(Data[2])
            
            print("Temperature:", tempData)
            print("Humidity:", humiData)
            print("Light:", lightData)
            
            # Define condition for good drying weather
            if tempData >= 18 and humiData <= 60 and lightData >= 15:
                print("Good condition for hanging clothes!")
                xb.write(b'1\n')
            else:
                print("Not good condition for hanging clothes. Please bring it in!")
                xb.write(b'0\n')
                
            time.sleep(2)

    except ValueError:
        print("ValueError: Could not parse sensor data")
        continue
    except KeyboardInterrupt:
        break

xb.close()
print("Program shut down")
