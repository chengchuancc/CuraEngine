//Copyright (c) 2018 Ultimaker B.V.
//CuraEngine is released under the terms of the AGPLv3 or higher.

#ifndef SLICE_H
#define SLICE_H

#include "Scene.h" //To store the scene to slice.

namespace cura
{

/*
 * \brief Represents a command to slice something.
 *
 * This contains a scene and all metadata of a slice.
 */
class Slice
{
public:
    /*
     * \brief Creates a new Slice instance.
     */
    Slice();

    /*
     * \brief The scene that must be sliced.
     */
    Scene scene;

    /*
     * \brief Slice the scene, producing g-code output.
     * \param[out] output_gcode The resulting g-code.
     */
    void compute(std::string& output_gcode);

    /*
     * \brief Empty out the slice instance, restoring it as if it were a new
     * instance.
     *
     * Since you are not allowed to copy, move or assign slice objects, this is
     * the only way in which you can prepare for the next slice.
     */
    void reset();

private:
    /*
     * \brief Disallow copying slice objects since they are heavyweight.
     *
     * The slice is dark and full of data.
     */
    Slice(const Slice& other) = delete;

    /*
     * \brief Disallow copying slice objects.
     */
    Slice& operator =(const Slice& other) = delete;
};

} //namespace cura

#endif //SLICE_H