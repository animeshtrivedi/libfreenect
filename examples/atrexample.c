//
// Created by atr on 18.06.17.
//

#include <stdio.h>
#include <libfreenect.h>

int main(int argc, char **argv) {
    printf(" Hello world\n");
    printf("Kinect camera test\n");
    freenect_context *f_ctx;
    freenect_device *f_dev;

    if (freenect_init(&f_ctx, NULL) < 0) {
        printf("freenect_init() failed\n");
        return 1;
    }
    freenect_set_log_level(f_ctx, FREENECT_LOG_DEBUG);
    freenect_select_subdevices(f_ctx, (freenect_device_flags)(FREENECT_DEVICE_MOTOR | FREENECT_DEVICE_CAMERA));

    int nr_devices = freenect_num_devices (f_ctx);
    printf ("Number of devices found: %d\n", nr_devices);

    if (freenect_open_device(f_ctx, &f_dev, 1) < 0) {
        printf("Could not open device\n");
        freenect_shutdown(f_ctx);
        return 1;
    }

    return 0;
}