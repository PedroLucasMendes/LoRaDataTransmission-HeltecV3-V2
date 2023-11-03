import serial
import time
import os

porta_serial = '/dev/ttyUSB0'
baudrate = 115200
timeout = 1

def get_next_filename(base_filename):
    # Verifique se o arquivo base já existe
    if not os.path.exists(base_filename):
        return base_filename

    # Se o arquivo base já existe, crie um nome de arquivo sequencial
    base, ext = os.path.splitext(base_filename)
    index = 1
    while True:
        new_filename = f"{base}_{index}{ext}"
        if not os.path.exists(new_filename):
            return new_filename
        index += 1

def write_rea(arduino, output_filename):
    with open(output_filename, 'a') as arquivo_txt:
        while True:
            data = arduino.readline().decode().strip()
            if data:
                print(data)
                arquivo_txt.write(data + '\n')

def main():
    arduino = serial.Serial(port=porta_serial, baudrate=baudrate, timeout=timeout)
    base_filename = 'dados.txt'
    output_filename = get_next_filename(base_filename)
    print(f"Gravando dados em: {output_filename}")

    try:
        write_rea(arduino, output_filename)
    except KeyboardInterrupt:
        pass
    finally:
        arduino.close()

if __name__ == '__main__':
    main()
