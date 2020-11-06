// Higher definition curves
$fs = 0.01;

module roundedcube(size = [1, 1, 1], center = false, radius = 0.5, apply_to = "all") {
	// If single value, convert to [x, y, z] vector
	size = (size[0] == undef) ? [size, size, size] : size;

	translate_min = radius;
	translate_xmax = size[0] - radius;
	translate_ymax = size[1] - radius;
	translate_zmax = size[2] - radius;

	diameter = radius * 2;

	module build_point(type = "sphere", rotate = [0, 0, 0]) {
		if (type == "sphere") {
			sphere(r = radius);
		} else if (type == "cylinder") {
			rotate(a = rotate)
			cylinder(h = diameter, r = radius, center = true);
		}
	}

	obj_translate = (center == false) ?
		[0, 0, 0] : [
			-(size[0] / 2),
			-(size[1] / 2),
			-(size[2] / 2)
		];

	translate(v = obj_translate) {
		hull() {
			for (translate_x = [translate_min, translate_xmax]) {
				x_at = (translate_x == translate_min) ? "min" : "max";
				for (translate_y = [translate_min, translate_ymax]) {
					y_at = (translate_y == translate_min) ? "min" : "max";
					for (translate_z = [translate_min, translate_zmax]) {
						z_at = (translate_z == translate_min) ? "min" : "max";

						translate(v = [translate_x, translate_y, translate_z])
						if (
							(apply_to == "all") ||
							(apply_to == "xmin" && x_at == "min") || (apply_to == "xmax" && x_at == "max") ||
							(apply_to == "ymin" && y_at == "min") || (apply_to == "ymax" && y_at == "max") ||
							(apply_to == "zmin" && z_at == "min") || (apply_to == "zmax" && z_at == "max")
						) {
							build_point("sphere");
						} else {
							rotate = 
								(apply_to == "xmin" || apply_to == "xmax" || apply_to == "x") ? [0, 90, 0] : (
								(apply_to == "ymin" || apply_to == "ymax" || apply_to == "y") ? [90, 90, 0] :
								[0, 0, 0]
							);
							build_point("cylinder", rotate);
						}
					}
				}
			}
		}
	}
}



matrix_width=80;
case_height=10;
case_width=86;
case_length=86;
down_bar=5;

difference() {
// Main case
union() {
    difference() {
        difference() {
            union() {
                difference() {
                    translate([0, -down_bar/2, 0]) { roundedcube([case_width, case_length+down_bar, case_height], true, 1, "z"); }
                    translate([0, -down_bar/2, 1.5]) { cube([80, 85, case_height], true); } // inside box
                }
                translate([-14.5, -45, -3.5]) { cube([16,5,case_height-3.5]); }      // pestana botones
            }
            translate([0,-4, (case_height/2) - 1.5]) { cube([82, 90, 1.5], true); }  // Transparent plexy rail
            
        }
        translate([-40, -48, 4]) { cube([80, 4, 4]); } // Down bar 
    }
    translate([-5, -48, 2.7]) { cube([10, 1, 1]); }     // Plexi holder
    
}

    // bikepixels board guide
    translate([-30, -45.5, -4] ) {
        difference() {
        color("green") cube([60, 25, 2]);
        translate([16, -1,-0.5]) { cube([15, 6, 3]); }
        }
    }
    // Holes for cloth pins
    translate([35, 35, -10]) { cylinder(case_height*2, 2, 2); }
    translate([-35, 35, -10]) { cylinder(case_height*2, 2, 2); }
    translate([35, -40, -10]) { cylinder(case_height*2, 2, 2); }
    translate([-35, -40, -10]) { cylinder(case_height*2, 2, 2); }   
    

    translate([-1, -9, -4]) {
        union() {
            color("green") cube([43, 18, 3]);
            translate([44-9, 5, 3]) { color("gray") cube([10, 8, 3.5]); }
        }
    }
}


