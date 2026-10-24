import sys
import base64

XOR_KEY = 0x5A

def decrypt_umfd_payload(raw_base64):
    try:
        # 1. Naprawa błędów transmisji HTTP (zamiana spacji z powrotem na '+')
        cleaned = raw_base64.strip().replace(" ", "+")
        cleaned = "".join(cleaned.split())
        
        # 2. Korekta wyrównania bloku (Padding)
        missing_padding = len(cleaned) % 4
        if missing_padding:
            cleaned += '=' * (4 - missing_padding)
            
        # 3. Dekodowanie z Base64 do bajtów
        encrypted_bytes = base64.b64decode(cleaned)
        
        # 4. Operacja XOR kluczem 0x5A
        decrypted_bytes = bytes([b ^ XOR_KEY for b in encrypted_bytes])
        
        # 5. Wyświetlenie wyniku w czytelnej formie UTF-8
        return decrypted_bytes.decode('utf-8', errors='replace')
        
    except Exception as e:
        return f"Błąd krytyczny deszyfrowania: {str(e)}"

if __name__ == "__main__":
    
    print("========================================\n")
    
    print("[*] Wklej nowy ciąg z Pipedream i naciśnij Enter -> Ctrl+Z (Windows) lub Ctrl+D (Linux):")
    user_input = sys.stdin.read()
    if user_input.strip():
        print("\nWynik dekodowania:")
        print(decrypt_umfd_payload(user_input))