#include "abstractfractal.h"

AbstractFractal::AbstractFractal(QLineF _segment, int _deepness): segment(_segment), deepness(_deepness)
{
    double facteur = (deepness%10)/10.0;
    pen = QPen( QColor::fromHsvF(facteur,1,1) );
    pen.setWidth(0);
}

AbstractFractal::~AbstractFractal()
{

}



int AbstractFractal::getDeepness() const
{
    return deepness;
}
