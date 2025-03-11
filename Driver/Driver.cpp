#include <iostream>
#include <string>
#include "interception.h"
#include <windows.h>
#include <vector>

#define TARGET_ID "VID_09DA&PID_2269"
#define TARGET_VID "09DA"  
#define TARGET_PID "2269"  

// Коды функциональных клавиш
#define VK_F13 0x100
#define VK_F14 0x101
#define VK_F15 0x102
#define VK_F16 0x103
#define VK_F17 0x104
#define VK_F18 0x105
#define VK_F19 0x106
#define VK_F20 0x107
#define VK_F21 0x108
#define VK_F22 0x109
#define VK_F23 0x110
#define VK_F24 0x111
#define VK_F25 0x112
#define VK_F26 0x113
#define VK_F27 0x114
#define VK_F28 0x115

void SendUnicodeString(const std::wstring& text) {
    std::vector<INPUT> inputs;

    for (wchar_t ch : text) {
        INPUT input_down = { 0 };
        input_down.type = INPUT_KEYBOARD;
        input_down.ki.wVk = 0;
        input_down.ki.wScan = ch;
        input_down.ki.dwFlags = KEYEVENTF_UNICODE;

        INPUT input_up = { 0 };
        input_up.type = INPUT_KEYBOARD;
        input_up.ki.wVk = 0;
        input_up.ki.wScan = ch;
        input_up.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        inputs.push_back(input_down);
        inputs.push_back(input_up);
    }

    SendInput(static_cast<UINT>(inputs.size()), inputs.data(), sizeof(INPUT));
}

boolean keyPressed = false;

int main() {

    std::setlocale(LC_ALL, "Russian");
    InterceptionContext context = interception_create_context();
    InterceptionDevice device;
    InterceptionStroke stroke;

    // Устанавливаем фильтр: перехватываем нажатия только с клавиатуры
    interception_set_filter(context, interception_is_keyboard, INTERCEPTION_FILTER_KEY_DOWN | INTERCEPTION_FILTER_KEY_UP);

    std::cout << "Listening for external numpad..." << std::endl;

    while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0) {
        // Буфер для хранения hardware ID
        char hardware_id[500];
        unsigned int hardware_id_size = interception_get_hardware_id(context, device, hardware_id, sizeof(hardware_id));

        // Преобразуем hardware ID в строку
        //std::string hardware_id_str(hardware_id, hardware_id_size);

        std::string hardware_id_str;
        for (size_t i = 0; i < hardware_id_size; i += 2) {
            hardware_id_str.push_back(hardware_id[i]);
        }

        /*for (char c : TARGET_ID) {
            std::cout << "[" << (int)c << "]";
        }
        std::cout << std::endl;


        std::cout << "Hardware ID: " << hardware_id_str << std::endl << std::endl << std::endl;
        std::cout << std::string::npos << std::endl;
        std::cout << hardware_id_str.find(TARGET_ID) << std::endl;*/

        if (hardware_id_str.find(TARGET_ID) != std::string::npos) {

            InterceptionKeyStroke& kstroke = *(InterceptionKeyStroke*)&stroke;

            switch (kstroke.code) {
            case 69: kstroke.code = VK_F13; break;  // Перехвачено 69 → F13
            case 55: kstroke.code = VK_F14; break;
            case 74: kstroke.code = VK_F15; break;
            case 71: kstroke.code = VK_F16; break;
            case 72: kstroke.code = VK_F17; break;
            case 73: kstroke.code = VK_F18; break;
            case 78: kstroke.code = VK_F19; break;
            case 75: kstroke.code = VK_F20; break;
            case 76: kstroke.code = VK_F21; break;
            case 77: kstroke.code = VK_F22; break;
            case 14: kstroke.code = VK_F23; break;
            case 79: kstroke.code = VK_F24; break;
            case 80: kstroke.code = VK_F25; break;
            case 81: kstroke.code = VK_F26; break;
            case 82: kstroke.code = VK_F27; break;
            case 83: kstroke.code = VK_F28; break;
            default:
                interception_send(context, device, &stroke, 1);
                continue;
            }
            std::cout << (int)kstroke.code << std::endl;

            switch (kstroke.code) {
            case VK_F13:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F13");
                }
                break;
            case VK_F14:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F14");
                }
                break;
            case VK_F15:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F15");
                }
                break;
            case VK_F16:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F16");
                }
                break;
            case VK_F17:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F17");
                }
                break;
            case VK_F18:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F18");
                }
                break;
            case VK_F19:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F19");
                }
                break;
            case VK_F20:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F20");
                }
                break;
            case VK_F21:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F21");
                }
                break;
            case VK_F22:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F22");
                }
                break;
            case VK_F23:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F23");
                }
                break;
            case VK_F24:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F24");
                }
                break;
            case VK_F25:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F25");
                }
                break;
            case VK_F26:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F26");
                }
                break;
            case VK_F27:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F27");
                }
                break;
            case VK_F28:
                keyPressed = !keyPressed;
                if (!keyPressed) {
                    SendUnicodeString(L"F28");
                }
                break;
            default:
                interception_send(context, device, &stroke, 1);
                continue;
            }
            // Отправляем преобразованное событие
            interception_send(context, device, &stroke, 1);
        }
        else {
            // Если устройство не является целевым, передаем событие без изменений
            interception_send(context, device, &stroke, 1);
        }

    }

    // todo.tips: Не открывать консоль

    interception_destroy_context(context);
    return 0;
}