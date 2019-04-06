import whycpp


def on_create():
    whycpp.log_info("OnCreate!!!!!")


def on_render():
    w = whycpp.get_display_width() // whycpp.PALETTE_LEN
    for i in range(whycpp.PALETTE_LEN):
        whycpp.draw_rect_fill(i * w, 0, w, whycpp.get_display_height(), whycpp.PALETTE(i))

    whycpp.print("Hello there!", 20, 50, whycpp.PALETTE(0), 3, 4)
