#!/usr/bin/env python3
import sys
import subprocess

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 econ.py <number | numberpy>")
        sys.exit(1)

    arg = sys.argv[1]

    if arg.endswith("py"):
        num = arg[:-2]
        cmd = ["python3", f"econ{num}.py"]
    else:
        cmd = [f"./econ{arg}"]

    try:
        # Aufruf der externen Datei
        result = subprocess.run(cmd, check=True)
        sys.exit(result.returncode)
    except FileNotFoundError:
        print(f"Error: Command '{' '.join(cmd)}' not found.")
        sys.exit(1)
    except subprocess.CalledProcessError as e:
        print(f"Error: Command '{' '.join(cmd)}' exited with {e.returncode}")
        sys.exit(e.returncode)

if __name__ == "__main__":
    main()
