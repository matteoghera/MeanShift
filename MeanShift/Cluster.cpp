#include <cmath>
#include <vector>

#include "Cluster.h"
#include "Point.h"

Cluster::Cluster(Point centroid)
{
    this->centroid = std::move(centroid);
}

Point Cluster::getCentroid() const
{
    return centroid;
}

bool Cluster::operator==(const Cluster &c) const
{
    return this->centroid == c.centroid;
}

bool Cluster::operator!=(const Cluster &c) const
{
    return this->centroid != c.centroid;
}

void Cluster::addPoint(Point point)
{
    points.emplace_back(point);
}

long Cluster::getSize() const
{
    return points.size();
}

std::vector<Point>::iterator Cluster::begin()
{
    return points.begin();
}

std::vector<Point>::iterator Cluster::end()
{
    return points.end();
}

double Cluster::getSse() const
{
    double sum = 0.0;
    for (const Point &p : points)
        sum += std::pow(p.euclideanDistance(centroid), 2);
    return sum;
}