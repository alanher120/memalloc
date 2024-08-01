memory_hog = []
try:
    while True:
        # Allocate a large chunk of memory (e.g., 100 MB) to accelerate the process
        memory_hog.append(bytearray(100 * 1024 * 1024))
        print(f"Memory allocation {len(memory_hog) * 100} MB")
        
except MemoryError:
    print(f"Memory allocation failed after {len(memory_hog) * 100} MB")

print("按 Enter 鍵以繼續...")
input()  # 等待使用者按下 Enter 鍵
