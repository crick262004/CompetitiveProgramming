# IS_SET

bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}