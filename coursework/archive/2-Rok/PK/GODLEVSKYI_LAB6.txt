#Godlevskyi Andrii

def generate_domain(bitlen: int = 256):

    while True:
        q = random_prime(2 ** (bitlen - 1) - 1, lbound=2 ** (bitlen - 2))
        p = 2 * q + 1
        if is_prime(p):
            while True:
                h = randint(2, p - 2)
                g = pow(h, 2, p)
                if g != 1:
                    return p, q, g


def keygen(p: int, q: int, g: int):
    x = randint(2, q - 1)
    y = pow(g, x, p)
    return x, y

#  =======  Protokół ślepego podpisu  =======

def blind_signature_protocol(m: int, params, x: int, y: int, *, verbose: bool = True):

    p, q, g = params
    Zq = Integers(q)

    # -----------  Krok 1 (B)  -----------
    while True:
        k = randint(2, q - 1)     
        R = pow(g, k, p)
        if gcd(R, q) == 1:
            break

    if verbose:
        print("Krok 1:")
        print("B wybiera k i oblicza R.")
        print(f"k = {k}\nR = {R}\nB wysyła do A: R = {R}\n")

    # -----------  Krok 2 (A)  -----------
    if gcd(R, q) != 1:
        raise ValueError("R i q nie są względnie pierwsze — przerwanie protokołu.")

    if verbose:
        print("Krok 2:")
        print(f"R = {R} ")
        print(f"q = {q} ")
        print(f"A sprawdza NWD(R,q) = {gcd(R,q)} (ma być 1) — ok.\n")

    # -----------  Krok 3 (A)  -----------
    while True:
        a = randint(0, q - 1)         
        b = randint(1, q - 1)             
        r = ((m % p) * pow(g, a, p) * pow(R, b, p)) % p
        m_prime = (Zq(r) * Zq(b).inverse()).lift()
        if 1 <= m_prime <= q - 1:
            break

    if verbose:
        print("Krok 3:")
        print("A wybiera a, b i oblicza r:")
        print(f"a = {a}\nb = {b}\nr = {r}\n")

    # -----------  Krok 4 (A)  -----------
    if verbose:
        print("Krok 4:")
        print("A oblicza m':")
        print(f"m' = {m_prime}\nA wysyła do B: m' = {m_prime}\n")

    # -----------  Krok 5 (B)  -----------
    s_prime = (m_prime * x + k) % q

    if verbose:
        print("Krok 5:")
        print("B oblicza s' i wysyła do A:")
        print(f"s' = {s_prime}\nB wysyła do A: s' = {s_prime}\n")

    # -----------  Krok 6 (A)  -----------
    s = (s_prime * b + a) % q

    if verbose:
        print("Krok 6:")
        print("A usuwa zaciemnienie i otrzymuje podpis (r,s):")
        print(f"(r,s) = ({r},{s})\n")

    return r, s

#  =======  Weryfikacja podpisu  =======

def verify_signature(m: int, signature, params, y: int, *, verbose: bool = True):

    r, s = signature
    p, q, g = params

    g_inv_s = pow(g, q - s % q, p)
    y_pow_r = pow(y, r, p)
    m_test = (g_inv_s * y_pow_r * (r % p)) % p

    if verbose:
        print("Krok 7:")
        print("C oblicza m'':")
        print(f"m = {m}")
        print(f"m''= {m_test}\n")
        print("Krok 8:")
        wynik = "POPRAWNY" if m_test == (m % p) else "BŁĘDNY"
        print(f"C porównuje m'' z m. Wynik weryfikacji: {wynik}\n")
    return m_test == (m % p)

#  =======  Symulacje  =======

def symulacja_blind_signature(bitlen: int, case: int = 1):
    # Parametry domeny i klucze
    p, q, g = generate_domain(bitlen)
    x, y = keygen(p, q, g)
    m = randint(2, q - 1)     

    print("Krok 0:")
    print("Ustalono parametry i klucze:")
    print(f"p = {p}\nq = {q}\ng = {g}")
    print(f"x = {x}\ny = {y}")
    print(f"m = {m}\n")

 
    signature = blind_signature_protocol(m, (p, q, g), x, y, verbose=True)
    r, s = signature

    # --- Weryfikacje zależnie od scenariusza ---
    if case == 1:
        verify_signature(m, signature, (p, q, g), y, verbose=True)

    elif case == 2:
        m_tampered = (m + 1) % q or 2
        if m_tampered == m:
            m_tampered = (m + 2) % q or 2
            
        print(f"Stara wiadomość m = {m}")
        print(f"Nowa wiadomość m`= {m_tampered}\n")
        verify_signature(m_tampered, signature, (p, q, g), y, verbose=True)

    elif case == 3:
        x_fake = randint(2, q - 1)
        y_fake = pow(g, x_fake, p)
        print(f"Prawdziwy klucz publiczny y = {y}")
        print(f"Fałszywy klucz publiczny y` = {y_fake}\n")
        verify_signature(m, signature, (p, q, g), y_fake, verbose=True)

    elif case == 4:
        s_tampered = (s + 1) % q or 1
        print(f"Oryginalne s = {s}")
        print(f"Podmienione s = {s_tampered}\n")
        verify_signature(m, (r, s_tampered), (p, q, g), y, verbose=True)

    else:
        raise ValueError("case musi byc od 1 do 4")



bitlen = 64
print(f"Długość liczby p w bitach: {bitlen}")

print("============SYMULACJA 1 (Poprawna)============")
symulacja_blind_signature(bitlen, case=1)

print("============SYMULACJA 2 (Inna wiadomość)============")
symulacja_blind_signature(bitlen, case=2)

print("============SYMULACJA 3 (Inny klucz publiczny)============")
symulacja_blind_signature(bitlen, case=3)

print("============SYMULACJA 4 (Zmodyfikowany podpis)============")
symulacja_blind_signature(bitlen, case=4)
