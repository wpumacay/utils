#include <tinyutils/path_handling.hpp>
#include <tinyutils/logging.hpp>

int main()
{
    tinyutils::Logger::Init( tinyutils::Logger::eType::CONSOLE_LOGGER );

    {
        std::string abs_path = "/home/ratatouille/dish/animal/object.obj";
        LOG_TRACE( "FROM ABSOLUTE PATH: " );
        LOG_TRACE( "filename: {0}", tinyutils::GetFilename( abs_path ) );
        LOG_TRACE( "folder_name: {0}", tinyutils::GetFoldername( abs_path ) );
        LOG_TRACE( "folder_path: {0}", tinyutils::GetFolderpath( abs_path ) );
        LOG_TRACE( "filename_no_ext: {0}", tinyutils::GetFilenameNoExtension( abs_path ) );
    }

    {
        std::string rel_path = "./dish/animal/object.obj";
        LOG_INFO( "FROM RELATIVE PATH: " );
        LOG_INFO( "filename: {0}", tinyutils::GetFilename( rel_path ) );
        LOG_INFO( "folder_name: {0}", tinyutils::GetFoldername( rel_path ) );
        LOG_INFO( "folder_path: {0}", tinyutils::GetFolderpath( rel_path ) );
        LOG_INFO( "filename_no_ext: {0}", tinyutils::GetFilenameNoExtension( rel_path ) );
    }

    return 0;
}