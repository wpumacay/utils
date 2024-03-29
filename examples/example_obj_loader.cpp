
#include <utils/logging.hpp>
#include <utils/obj_loader.hpp>

constexpr const char* OBJ_GEOM_STR = R"(
# cube.obj
#

o cube
mtllib cube.mtl

v -0.500000 -0.500000 0.500000
v 0.500000 -0.500000 0.500000
v -0.500000 0.500000 0.500000
v 0.500000 0.500000 0.500000
v -0.500000 0.500000 -0.500000
v 0.500000 0.500000 -0.500000
v -0.500000 -0.500000 -0.500000
v 0.500000 -0.500000 -0.500000

vt 0.000000 0.000000
vt 1.000000 0.000000
vt 0.000000 1.000000
vt 1.000000 1.000000

vn 0.000000 0.000000 1.000000
vn 0.000000 1.000000 0.000000
vn 0.000000 0.000000 -1.000000
vn 0.000000 -1.000000 0.000000
vn 1.000000 0.000000 0.000000
vn -1.000000 0.000000 0.000000

g cube
usemtl cube
s 1
f 1/1/1 2/2/1 3/3/1
f 3/3/1 2/2/1 4/4/1
s 2
f 3/1/2 4/2/2 5/3/2
f 5/3/2 4/2/2 6/4/2
s 3
f 5/4/3 6/3/3 7/2/3
f 7/2/3 6/3/3 8/1/3
s 4
f 7/1/4 8/2/4 1/3/4
f 1/3/4 8/2/4 2/4/4
s 5
f 2/1/5 8/2/5 4/3/5
f 4/3/5 8/2/5 6/4/5
s 6
f 7/1/6 1/2/6 5/3/6
f 5/3/6 1/2/6 3/4/6


)";

constexpr const char* OBJ_MTL_STR = R"(
newmtl cube
  Ns 10.0000
  Ni 1.5000
  d 1.0000
  Tr 0.0000
  Tf 1.0000 1.0000 1.0000
  illum 2
  Ka 0.0000 0.0000 0.0000
  Kd 0.5880 0.5880 0.5880
  Ks 0.0000 0.0000 0.0000
  Ke 0.0000 0.0000 0.0000
  map_Ka cube.tga
  map_Kd cube.png
)";

auto main() -> int {
    auto data = ::utils::ParseObjFromString(OBJ_GEOM_STR, OBJ_MTL_STR);

    LOG_INFO("# of vertices: {0}", data.vertices.size());
    LOG_INFO("# of normals: {0}", data.normals.size());
    LOG_INFO("# of texcoords: {0}", data.texcoords.size());

    return 0;
}
