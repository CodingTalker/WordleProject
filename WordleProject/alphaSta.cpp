#include "alphaSta.h"	

alphaSta::alphaSta():alpha(0),sta(0){
}

bool alphaSta::operator==(const alphaSta& right) const{
    return this->alpha == right.alpha && this->sta == right.sta && this->pos[0] == right.pos[0];
}

bool alphaSta::operator>(const alphaSta& right) const
{
    if (this->sta == 'b')
    {
        if (right.sta == 'b') {
            if (this->pos[0] == right.pos[0])
                return this->alpha > right.alpha;
            else
                return this->pos[0] > right.pos[0];
        }
        else
            return true;
    }
    else if (this->sta == 'y') {
        if (right.sta == 'b')
            return false;
        else if (right.sta == 'y') {
            if (this->pos[0] == right.pos[0])
                return this->alpha > right.alpha;
            else
                return this->pos[0] > right.pos[0];
        }
        else if (right.sta == 'g')
            return true;
    }
    else if (this->sta == 'g')
    {
        if (right.sta == 'g') {
            if (this->pos[0] == right.pos[0])
                return this->alpha > right.alpha;
            else
                return this->pos[0] > right.pos[0];
        }
        else
            return false;
    }
}

bool alphaSta::operator<(const alphaSta& right) const
{
    if (this->sta == 'g')
    {
        if (right.sta == 'g') {
            if (this->pos[0] == right.pos[0])
                return this->alpha < right.alpha;
            else
                return this->pos[0] < right.pos[0];
        }
        else
            return true;
    }
    else if (this->sta == 'y') {
        if (right.sta == 'g')
            return false;
        else if (right.sta == 'y') {
            if (this->pos[0] == right.pos[0])
                return this->alpha < right.alpha;
            else
                return this->pos[0] < right.pos[0];
        }
        else if (right.sta == 'b')
            return true;
    }
    else if (this->sta == 'b')
    {
        if (right.sta == 'b') {
            if (this->pos[0] == right.pos[0])
                return this->alpha < right.alpha;
            else
                return this->pos[0] < right.pos[0];
        }
        else
            return false;
    }
}

