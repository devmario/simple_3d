simple_3d
=========

simple 3d calulator c++

```c++
simple_3d::camera camera;
std::list<simple_3d::point_update> points;

camera.y = 80;
camera.perspective = 50;

for(int i = 0; i < 300; i++) {
  simple_3d::point_update _point;
  _point.x = rand() % 1000 - 500;
  _point.y = rand() % 1000 - 500;
  _point.z = rand() % 1000 - 500;
  points.push_back(_point);
}

for(auto _point : points) {
  std::cout << "===============\n";
  _point.update(camera);
  std::cout << "position x:" << _point.result.x << ", y:" << _point.result.y << "\n";
  std::cout << "scale:" << _point.scale_ratio << "\n";
  std::cout << "delth:" << _point.result.z << "\n";
}
```
