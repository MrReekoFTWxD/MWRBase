#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <Windows.h>
#include <sdkddkver.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <map>
#include <unordered_map>
#include <thread>
#include <string>
#include <cstring>
#include <math.h>
#include <conio.h>
#include <detours.h>
#include <functional>
#include <optional>
#include <d3d11.h>
#include <fstream>
#include <deque>
#include <mutex>
#include <assert.h> 
#include <filesystem>
#include <codecvt>
#include <queue> 

using namespace std::chrono_literals;
using namespace std::literals;

#pragma comment(lib, "detours.lib")