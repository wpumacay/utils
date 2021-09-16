#include <tinyutils/common.hpp>
#include <tinyutils/logging.hpp>

int main() {
    tiny::utils::Logger::Init(tiny::utils::Logger::eType::FILE_LOGGER);

    auto vec_str = tiny::utils::Split("comp1/comp2", '/');
    assert(vec_str.size() == 2);

    auto address = tiny::utils::PointerToHexAddress(&vec_str);

    // Core logs
    {
        LOG_CORE_TRACE("This is a core log-trace sample");
        LOG_CORE_INFO("Just an address: {0}", address);
        for (size_t i = 0; i < vec_str.size(); i++)
            LOG_CORE_WARN("comp: {0}", vec_str[i]);
    }

    // User logs
    {
        LOG_TRACE("This is an user log-trace sample");
        LOG_INFO("Just an address: {0}", address);
        for (size_t i = 0; i < vec_str.size(); i++)
            LOG_WARN("comp: {0}", vec_str[i]);
    }

    return 0;
}
