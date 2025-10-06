# ft_printf

A custom implementation of the C standard library's `printf` function, created as part of the 42 School curriculum.

---

## 📋 Table of Contents

### English
- [About](#about)
- [Features](#features)
- [Supported Conversions](#supported-conversions)
- [Installation](#installation)
- [Usage](#usage)
- [Function Prototypes](#function-prototypes)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Author](#author)

### Türkçe
- [Hakkında](#hakkında)
- [Özellikler](#özellikler)
- [Desteklenen Dönüşümler](#desteklenen-dönüşümler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım-tr)
- [Fonksiyon Prototipleri](#fonksiyon-prototipleri-tr)
- [Örnekler](#örnekler-tr)
- [Proje Yapısı](#proje-yapısı)
- [Derleme](#derleme)
- [Yazar](#yazar)

---

## English Documentation

### About

`ft_printf` is a recreation of the standard C library function `printf`. This project is part of the 42 School curriculum and aims to deepen understanding of variadic functions, type conversion, and formatted output in C.

The function mimics the behavior of the original `printf` by accepting a format string with conversion specifiers and variable arguments, then outputting the formatted result to standard output.

### Features

- ✅ **Variadic Function Implementation**: Uses `va_list`, `va_start`, and `va_end`
- ✅ **Multiple Conversion Specifiers**: Supports characters, strings, integers, hexadecimal, and pointers
- ✅ **Character Counting**: Returns the total number of characters printed
- ✅ **Modular Design**: Clean separation of concerns with utility functions
- ✅ **42 Norm Compliant**: Written according to 42 School coding standards

### Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Print a single character |
| `%s` | Print a string |
| `%p` | Print a pointer address in hexadecimal format (0x...) |
| `%d` | Print a signed decimal integer |
| `%i` | Print a signed integer |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print a number in hexadecimal (lowercase) |
| `%X` | Print a number in hexadecimal (uppercase) |
| `%%` | Print a percent sign |

### Installation

Clone the repository:

```bash
git clone https://github.com/cilginsinek/ft_printf.git
cd ft_printf
```

Compile the library:

```bash
make
```

This will create the static library `libftprintf.a`.

### Usage

Include the header in your C file:

```c
#include "myprintf.h"
```

Compile your program with the library:

```bash
cc your_file.c libftprintf.a
```

### Function Prototypes

#### Main Function
```c
int ft_printf(const char *format, ...);
```

#### Utility Functions
```c
void ft_putchar_counter(char c, int *count);
void ft_putstr_counter(const char *c, int *count);
void ft_putnbr_counter(int n, int *count);
void ft_puthex_counter(int n, int *count, char *base);
void ft_pointer_counter(size_t n, int *count, char *base);
```

### Examples

```c
#include "myprintf.h"

int main(void)
{
    int len;
    
    // Character and string
    len = ft_printf("Hello, %s!\n", "World");
    ft_printf("Characters printed: %d\n", len);
    
    // Numbers
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    
    // Hexadecimal
    ft_printf("Hex (lowercase): %x\n", 255);
    ft_printf("Hex (uppercase): %X\n", 255);
    
    // Pointer
    int x = 42;
    ft_printf("Pointer: %p\n", &x);
    
    // Percent sign
    ft_printf("Progress: 100%%\n");
    
    return 0;
}
```

### Project Structure

```
ft_printf/
├── ft_printf.c      # Main ft_printf implementation and formatter
├── utils.c          # Utility functions for output and conversion
├── myprintf.h       # Header file with function prototypes
├── Makefile         # Build configuration
└── README.md        # Project documentation
```

### Compilation

The Makefile includes the following rules:

- `make` or `make all`: Compile the library
- `make clean`: Remove object files
- `make fclean`: Remove object files and the library
- `make re`: Recompile everything from scratch

Compilation flags: `-Wall -Wextra -Werror`

### Author

**iduman** - [GitHub Profile](https://github.com/cilginsinek)

42 Istanbul Student

---

## Türkçe Dokümantasyon

### Hakkında

`ft_printf`, standart C kütüphanesinin `printf` fonksiyonunun yeniden yazılmış halidir. Bu proje, 42 Okulu müfredatının bir parçasıdır ve variadic fonksiyonlar, tip dönüşümü ve C dilinde biçimlendirilmiş çıktı konularında derin bir anlayış kazandırmayı amaçlar.

Fonksiyon, orijinal `printf` davranışını taklit ederek dönüşüm belirteçleri içeren bir format dizesi ve değişken argümanlar alır, ardından biçimlendirilmiş sonucu standart çıktıya yazar.

### Özellikler

- ✅ **Variadic Fonksiyon Uygulaması**: `va_list`, `va_start` ve `va_end` kullanımı
- ✅ **Çoklu Dönüşüm Belirteçleri**: Karakter, string, tamsayı, onaltılık ve pointer desteği
- ✅ **Karakter Sayımı**: Yazdırılan toplam karakter sayısını döndürür
- ✅ **Modüler Tasarım**: Yardımcı fonksiyonlarla temiz sorumluluk ayrımı
- ✅ **42 Norm Uyumlu**: 42 Okulu kodlama standartlarına göre yazılmıştır

### Desteklenen Dönüşümler

| Belirteç | Açıklama |
|----------|----------|
| `%c` | Tek bir karakter yazdır |
| `%s` | Bir string yazdır |
| `%p` | Pointer adresini onaltılık formatta yazdır (0x...) |
| `%d` | İşaretli ondalık tamsayı yazdır |
| `%i` | İşaretli tamsayı yazdır |
| `%u` | İşaretsiz ondalık tamsayı yazdır |
| `%x` | Sayıyı onaltılık sistemde yazdır (küçük harf) |
| `%X` | Sayıyı onaltılık sistemde yazdır (büyük harf) |
| `%%` | Yüzde işareti yazdır |

### Kurulum

Projeyi klonlayın:

```bash
git clone https://github.com/cilginsinek/ft_printf.git
cd ft_printf
```

Kütüphaneyi derleyin:

```bash
make
```

Bu komut `libftprintf.a` statik kütüphanesini oluşturacaktır.

### Kullanım {#kullanım-tr}

Header dosyasını C dosyanıza dahil edin:

```c
#include "myprintf.h"
```

Programınızı kütüphane ile derleyin:

```bash
cc your_file.c libftprintf.a
```

### Fonksiyon Prototipleri {#fonksiyon-prototipleri-tr}

#### Ana Fonksiyon
```c
int ft_printf(const char *format, ...);
```

#### Yardımcı Fonksiyonlar
```c
void ft_putchar_counter(char c, int *count);
void ft_putstr_counter(const char *c, int *count);
void ft_putnbr_counter(int n, int *count);
void ft_puthex_counter(int n, int *count, char *base);
void ft_pointer_counter(size_t n, int *count, char *base);
```

### Örnekler {#örnekler-tr}

```c
#include "myprintf.h"

int main(void)
{
    int len;
    
    // Karakter ve string
    len = ft_printf("Merhaba, %s!\n", "Dünya");
    ft_printf("Yazdırılan karakter sayısı: %d\n", len);
    
    // Sayılar
    ft_printf("Ondalık: %d\n", 42);
    ft_printf("Tamsayı: %i\n", -42);
    ft_printf("İşaretsiz: %u\n", 42);
    
    // Onaltılık
    ft_printf("Hex (küçük harf): %x\n", 255);
    ft_printf("Hex (büyük harf): %X\n", 255);
    
    // Pointer
    int x = 42;
    ft_printf("Pointer: %p\n", &x);
    
    // Yüzde işareti
    ft_printf("İlerleme: 100%%\n");
    
    return 0;
}
```

### Proje Yapısı

```
ft_printf/
├── ft_printf.c      # Ana ft_printf implementasyonu ve formatlayıcı
├── utils.c          # Çıktı ve dönüşüm için yardımcı fonksiyonlar
├── myprintf.h       # Fonksiyon prototiplerini içeren header dosyası
├── Makefile         # Derleme yapılandırması
└── README.md        # Proje dokümantasyonu
```

### Derleme

Makefile aşağıdaki kuralları içerir:

- `make` veya `make all`: Kütüphaneyi derle
- `make clean`: Nesne dosyalarını sil
- `make fclean`: Nesne dosyalarını ve kütüphaneyi sil
- `make re`: Her şeyi sıfırdan yeniden derle

Derleme bayrakları: `-Wall -Wextra -Werror`

### Yazar

**iduman** - [GitHub Profili](https://github.com/cilginsinek)

42 İstanbul Öğrencisi

---

## 📝 License

This project is part of the 42 School curriculum. Feel free to use and modify for educational purposes.

---

⭐ If you found this project useful, please consider giving it a star!
