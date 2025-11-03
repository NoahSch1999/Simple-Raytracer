#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "SimpleRaytracer.h"
#include <vector>
#include <algorithm>

int main()
{
	constexpr int WIDTH = 512;
	constexpr int HEIGHT = 512;
	constexpr int CHANNELS = 3;
	constexpr int NUM_8BIT = WIDTH * HEIGHT * CHANNELS;
	constexpr double lightRange = 500;
	std::vector<uint8_t> imageData(NUM_8BIT);

	std::vector<std::unique_ptr<Shape>> shapes;
	shapes.emplace_back(std::make_unique<Sphere>(Sphere(Vector3D(255, 0, 0), Vector3D(100, HEIGHT / 2.0, 170), 50)));
	shapes.emplace_back(std::make_unique<Plane>(Plane(Vector3D(255.0, 0.0, 255.0), Vector3D(0, 0, -1), 170)));
	shapes.emplace_back(std::make_unique<Triangle>(Triangle(Vector3D(255, 0, 0), Vector3D(200, 400, 50), Vector3D(400, HEIGHT / 2.0, 150), Vector3D(400, 100, 100))));
	shapes.emplace_back(std::make_unique<Sphere>(Sphere(Vector3D(0, 255, 0), Vector3D(400, HEIGHT / 2.0, 110), 70)));
	shapes.emplace_back(std::make_unique<OBB>(OBB(Vector3D(255, 150, 0), Vector3D(200, HEIGHT / 2.0, 150), Vector3D(0.5, 0, -0.866), Vector3D(0.749, 0.5, 0.433), Vector3D(0.433, -0.866, 0.25), 100, 100, 100)));

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int x = 0; x < WIDTH; x++) 
		{
			const Ray ray({ static_cast<double>(x), static_cast<double>(i), 0 }, { 0,0,1 });
			const int currentPixel = (i * WIDTH + x) * CHANNELS;
			double currentClosest = std::numeric_limits<double>::max();
			imageData[currentPixel + 0] = 0;
			imageData[currentPixel + 1] = 0;
			imageData[currentPixel + 2] = 0;

			for (const auto& shape : shapes)
			{
				double t = 0;
				if (shape->Intersection(ray, t) && t < currentClosest)
				{
					const Vector3D& color = shape->GetColor();
					double lightFactor = std::min(std::max(1.0 - (t / lightRange), 0.0), 1.0);
					imageData[currentPixel + 0] = static_cast<uint8_t>(color.x * lightFactor);
					imageData[currentPixel + 1] = static_cast<uint8_t>(color.y * lightFactor);
					imageData[currentPixel + 2] = static_cast<uint8_t>(color.z * lightFactor);

					currentClosest = t;
				}
			}
		}
	}

	stbi_write_png("renderOutput.png", WIDTH, HEIGHT, CHANNELS, imageData.data(), WIDTH * CHANNELS);

	return 0;
}