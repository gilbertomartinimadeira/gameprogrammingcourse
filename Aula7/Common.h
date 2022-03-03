

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Vec2.h"

template <class T> using ptr = std::shared_ptr<T>;

template <class M> using uptr = std::unique_ptr<M>;
