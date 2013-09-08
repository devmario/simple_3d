//
//  simple_3d.h
//  DessertTown
//
//  Created by wonhee jang on 13. 9. 4..
//  Copyright (c) 2013년 vanillabreeze. All rights reserved.
//

#ifndef __DessertTown__simple_3d__
#define __DessertTown__simple_3d__

#include <iostream>
#include <math.h>
#include <map>
#include <list>

namespace simple_3d {
	class point {
	public:
		float x;
		float y;
		float z;
		
		point() {
			x = y = z = 0.0f;
		};
	};
	
	class camera  : public point {
	private:
		point sin;
		point cos;
		
	public:
		float perspective;
		
		point rotation;
		
		void update() {
			sin.x = sinf(rotation.x);
			sin.y = sinf(rotation.y);
			sin.z = sinf(rotation.z);
			cos.x = cosf(rotation.x);
			cos.y = cosf(rotation.y);
			cos.z = cosf(rotation.z);
		};
		
		friend class point_update;
	};
	
	class point_update : public point {
	public:
		point result;
		
		float scale_ratio;
		
		void update(camera& _camera) {
			float _xy = _camera.cos.x * (y - _camera.y) - _camera.sin.x * (z - _camera.z);
			float _xz = _camera.sin.x * (y - _camera.y) - _camera.cos.x * (z - _camera.z);
			float _yz = _camera.cos.y * _xz - _camera.sin.y * (x - _camera.x);
			float _yx = _camera.sin.y * _xz + _camera.cos.y * (x - _camera.x);
			float _zx = _camera.cos.z * _yx - _camera.sin.z * _xy;
			float _zy = _camera.sin.z * _yx + _camera.cos.z * _xy;
			
			scale_ratio = _camera.perspective / (_camera.perspective + _yz);
			result.x = _zx * scale_ratio;
			result.y = _zy * scale_ratio;
			result.z = _yz;
		}
	};
};

#endif /* defined(__DessertTown__simple_3d__) */
