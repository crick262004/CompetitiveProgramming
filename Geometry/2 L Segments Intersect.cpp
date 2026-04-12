// 2 L Segments Intersect?

bool intersect(P p1, P p2, P p3, P p4){
    if((p2 - p1 )* (p4 - p3) == 0){ // line segments are parallel
        if(p1.triangle(p2, p3) != 0){
            return false;
        } else { // now need to check bounding boxes.
            for(int rep = 0; rep < 2; rep++){
                if(max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)){
                    return false;
                }
                swap(p1, p3);
                swap(p2, p4);
            }
            return true;
        }
    } else{ // line segs not parallel
        for(int rep = 0; rep < 2; rep++){
            if(p1.triangle(p2, p3)>0 && p1.triangle(p2, p4) > 0){
                return false;
            }
            if(p1.triangle(p2, p3)<0 && p1.triangle(p2, p4) < 0){
                return false;
            } 

            swap(p1, p3);
            swap(p2, p4);
        }
        return true;
    }
}