# Point wrt Line Segment


bool segment_contains(*P* p1, *P* p2, *P* p3){

    return((p1.triangle(p2, p3) == 0) && 
            (min(p1.x, p2.x) <= p3.x && max(p1.x, p2.x) >= p3.x) && 
            (min(p1.y, p2.y) <= p3.y && max(p1.y, p2.y) >= p3.y) 
            );
}
