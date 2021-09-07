#include <tinyutils/logging.hpp>
#include <tinyutils/path_handling.hpp>

int main() {
    tiny::utils::Logger::Init(tiny::utils::Logger::eType::CONSOLE_LOGGER);

    {
        std::string abs_path = "/home/ratatouille/dish/animal/object.obj";
        LOG_TRACE("FROM ABSOLUTE PATH: ");
        LOG_TRACE("filename: {0}", tiny::utils::GetFilename(abs_path));
        LOG_TRACE("folder_name: {0}", tiny::utils::GetFoldername(abs_path));
        LOG_TRACE("folder_path: {0}", tiny::utils::GetFolderpath(abs_path));
        LOG_TRACE("filename_no_ext: {0}",
                  tiny::utils::GetFilenameNoExtension(abs_path));
    }

    {
        std::string rel_path = "./dish/animal/object.obj";
        LOG_INFO("FROM RELATIVE PATH: ");
        LOG_INFO("filename: {0}", tiny::utils::GetFilename(rel_path));
        LOG_INFO("folder_name: {0}", tiny::utils::GetFoldername(rel_path));
        LOG_INFO("folder_path: {0}", tiny::utils::GetFolderpath(rel_path));
        LOG_INFO("filename_no_ext: {0}",
                 tiny::utils::GetFilenameNoExtension(rel_path));
    }

    return 0;
}
